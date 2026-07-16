#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount()
    : BankAccount(), annualRate(0.06), period(12), savingMonths(0), freePeriod(false) {}

SavingBankAccount::SavingBankAccount(const std::string& acctNum, const std::string& name, const std::string& id,
                                     double bal, double rate, int per, int months)
    : BankAccount(acctNum, name, id, bal), annualRate(rate), period(per), savingMonths(months), freePeriod(false) {}

SavingBankAccount::SavingBankAccount(const SavingBankAccount& other)
    : BankAccount(other), annualRate(other.annualRate), period(other.period),
      savingMonths(other.savingMonths), freePeriod(other.freePeriod) {}

SavingBankAccount::SavingBankAccount(const std::string& acctNum, const std::string& name,
                                     double rate, int per, int months)
    : BankAccount(acctNum, name), annualRate(rate), period(per), savingMonths(months), freePeriod(false) {}

SavingBankAccount::SavingBankAccount(const std::string& acctNum, double rate, int per, int months)
    : BankAccount(acctNum), annualRate(rate), period(per), savingMonths(months), freePeriod(false) {}

SavingBankAccount::~SavingBankAccount() {}

double SavingBankAccount::getEffectiveRate() const {
    return freePeriod ? 0.02 : annualRate;
}

void SavingBankAccount::inputInfo() {
    BankAccount::inputInfo();
    std::cout << "Enter annual interest rate (e.g. 0.06 for 6%): ";
    std::cin >> annualRate;
    std::cout << "Enter period (months): ";
    std::cin >> period;
    std::cout << "Enter saving months: ";
    std::cin >> savingMonths;
    std::cin.ignore();
    freePeriod = false;
}

void SavingBankAccount::displayInfo() const {
    BankAccount::displayInfo();
    std::cout << "Annual Rate: " << (annualRate * 100) << "%";
    if (freePeriod) std::cout << " (Free Period - 2% effective)";
    std::cout << std::endl;
    std::cout << "Period: " << period << " months" << std::endl;
    std::cout << "Saving Months: " << savingMonths << std::endl;
    std::cout << "Current Interest: " << checkInterest() << " VND" << std::endl;
}

void SavingBankAccount::deposit(double amount) {
    if (savingMonths < period) {
        std::cerr << "Cannot deposit: saving months (" << savingMonths
                  << ") < period (" << period << "). Create a new account instead."
                  << std::endl;
        return;
    }
    BankAccount::deposit(amount);
}

bool SavingBankAccount::withdraw(double amount) {
    if (savingMonths < period) {
        std::cerr << "Cannot withdraw: saving months (" << savingMonths
                  << ") < period (" << period << ")." << std::endl;
        return false;
    }
    return BankAccount::withdraw(amount);
}

bool SavingBankAccount::withdrawImmediately(double amount) {
    freePeriod = true;
    std::cout << "Immediate withdrawal. Account now free-period (2% rate)." << std::endl;
    return BankAccount::withdraw(amount);
}

double SavingBankAccount::checkBalance() const {
    return balance + checkInterest();
}

double SavingBankAccount::checkInterest() const {
    return balance * getEffectiveRate() * (savingMonths / 12.0);
}
