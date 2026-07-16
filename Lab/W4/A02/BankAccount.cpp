#include "BankAccount.h"

BankAccount::BankAccount() : balance(0) {}

BankAccount::BankAccount(const std::string& acctNum, const std::string& name, const std::string& id, double bal)
    : accountNumber(acctNum), ownerName(name), socialID(id), balance(bal) {}

BankAccount::BankAccount(const BankAccount& other)
    : accountNumber(other.accountNumber), ownerName(other.ownerName), socialID(other.socialID), balance(other.balance) {}

BankAccount::BankAccount(const std::string& acctNum, const std::string& name)
    : accountNumber(acctNum), ownerName(name), socialID(""), balance(0) {}

BankAccount::BankAccount(const std::string& acctNum)
    : accountNumber(acctNum), ownerName(""), socialID(""), balance(0) {}

BankAccount::~BankAccount() {}

void BankAccount::inputInfo() {
    std::cout << "Enter account number: ";
    std::getline(std::cin, accountNumber);
    std::cout << "Enter owner name: ";
    std::getline(std::cin, ownerName);
    std::cout << "Enter social ID: ";
    std::getline(std::cin, socialID);
    std::cout << "Enter initial balance: ";
    std::cin >> balance;
    std::cin.ignore();
}

void BankAccount::displayInfo() const {
    std::cout << "Account: " << accountNumber << std::endl;
    std::cout << "Owner: " << ownerName << std::endl;
    std::cout << "Balance: " << balance << " VND" << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cerr << "Deposit amount must be positive." << std::endl;
        return;
    }
    balance += amount;
    std::cout << "Deposited " << amount << " VND. New balance: " << balance << " VND" << std::endl;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cerr << "Withdraw amount must be positive." << std::endl;
        return false;
    }
    if (balance - amount < 50000) {
        std::cerr << "Insufficient balance. Minimum 50000 VND must remain." << std::endl;
        return false;
    }
    balance -= amount;
    std::cout << "Withdrew " << amount << " VND. New balance: " << balance << " VND" << std::endl;
    return true;
}

double BankAccount::checkBalance() const {
    return balance;
}
