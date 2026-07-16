#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Employee {
protected:
    std::string empId;
    std::string fullName;
    Date hireDate;
    std::string address;
public:
    Employee();
    Employee(const std::string& id, const std::string& name, const Date& date, const std::string& addr);
    Employee(const Employee& other);
    Employee(const std::string& id, const Date& date);
    explicit Employee(const std::string& data);
    virtual ~Employee();

    virtual void inputInfo();
    virtual void displayInfo() const;
    virtual double getSalary() const = 0;
};
