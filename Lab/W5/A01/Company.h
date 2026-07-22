#pragma once
#include <vector>
#include "Employee.h"

class Company {
private:
    std::vector<Employee*> list;
public:
    void addEmployee(Employee* emp);
    void inputEmployees();
    void displayEmployees() const;
    void displaySalaries() const;
    void bestPaidEmployees() const;

    Company();
    Company(const Company& c);
    Company& operator=(const Company& c);
    ~Company();
};
