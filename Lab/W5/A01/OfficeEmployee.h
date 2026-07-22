#pragma once
#include "Employee.h"

class OfficeEmployee : public Employee {
private:
    int workingDays;
public:
    OfficeEmployee();
    OfficeEmployee(const std::string& id, const std::string& name, const Date& date, const std::string& addr, int days);
    OfficeEmployee(const OfficeEmployee& other);
    OfficeEmployee(const std::string& id, const Date& date, int days);
    explicit OfficeEmployee(const std::string& data);
    ~OfficeEmployee();

    void inputInfo() override;
    void displayInfo() const override;
    void displayNameAndID() const override;
    double getSalary() const override;
    OfficeEmployee* clone() const override;
};
