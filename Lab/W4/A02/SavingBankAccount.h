#pragma once
#include "BankAccount.h"

class SavingBankAccount : public BankAccount {
private:
    double annualRate;
    int period;
    int savingMonths;
    bool freePeriod;
public:
    SavingBankAccount();
    SavingBankAccount(const std::string& acctNum, const std::string& name, const std::string& id,
                      double bal, double rate, int per, int months);
    SavingBankAccount(const SavingBankAccount& other);
    SavingBankAccount(const std::string& acctNum, const std::string& name, double rate, int per, int months);
    explicit SavingBankAccount(const std::string& acctNum, double rate = 0.06, int per = 12, int months = 0);
    ~SavingBankAccount();

    void inputInfo() override;
    void displayInfo() const override;
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    bool withdrawImmediately(double amount);
    double checkBalance() const override;
    double checkInterest() const;

    double getEffectiveRate() const;
};
