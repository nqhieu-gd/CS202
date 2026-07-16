#pragma once
#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    std::string ownerName;
    std::string socialID;
    double balance;
public:
    BankAccount();
    BankAccount(const std::string& acctNum, const std::string& name, const std::string& id, double bal);
    BankAccount(const BankAccount& other);
    BankAccount(const std::string& acctNum, const std::string& name);
    explicit BankAccount(const std::string& acctNum);
    virtual ~BankAccount();

    virtual void inputInfo();
    virtual void displayInfo() const;
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
    virtual double checkBalance() const;
};
