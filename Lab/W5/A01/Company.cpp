#include "Company.h"
#include "OfficeEmployee.h"
#include "Worker.h"
#include <iostream>

Company::Company() {}

void Company::addEmployee(Employee* emp) {
    list.push_back(emp);
}

void Company::inputEmployees() {
    int n;
    std::cout << "Enter number of employees: ";
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        int type;
        std::cout << "Enter type (1=OfficeEmployee, 2=Worker): ";
        std::cin >> type;
        std::cin.ignore();
        Employee* emp = nullptr;
        if (type == 1) {
            emp = new OfficeEmployee();
        } else {
            emp = new Worker();
        }
        emp->inputInfo();
        list.push_back(emp);
    }
}

void Company::displayEmployees() const {
    for (const auto& emp : list) {
        emp->displayInfo();
    }
}

void Company::displaySalaries() const {
    float pay = 0.0;
    for (const auto& emp : list) {
        pay += emp->getSalary();
    }
    std::cout << "Total Payroll: " << pay << " VND" << std::endl;
}

void Company::bestPaidEmployees() const {
    if (list.empty()) return;

    auto maxSalary = list[0]->getSalary();
    for (const auto& emp : list) {
        if (emp->getSalary() > maxSalary) {
            maxSalary = emp->getSalary();
        }
    }

    std::cout << "Best Paid Employees (Salary: " << maxSalary << " VND):" << std::endl;
    for (const auto& emp : list) {
        if (emp->getSalary() == maxSalary) {
            emp->displayNameAndID();
        }
    }
}

Company::Company(const Company& c) {
    list.resize(c.list.size(), nullptr);
    for (int i = 0; i < c.list.size(); i++) {
        if (c.list[i] != nullptr) {
            list[i] = c.list[i]->clone();
        }
    }
}

Company& Company::operator=(const Company& c) {
    if (this != &c) {
        for (auto& emp : list) delete emp;
        list.clear();
        list.reserve(c.list.size());
        for (auto* emp : c.list) {
            list.push_back(emp->clone());
        }
    }
    return *this;
}

Company::~Company() {
    for (auto& emp : list) {
        delete emp;
    }
}
