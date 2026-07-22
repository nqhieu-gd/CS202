#pragma once
#include "Employee.h"

class Worker : public Employee {
private:
    int producedItems;
public:
    Worker();
    Worker(const std::string& id, const std::string& name, const Date& date, const std::string& addr, int items);
    Worker(const Worker& other);
    Worker(const std::string& id, const Date& date, int items);
    explicit Worker(const std::string& data);
    ~Worker();

    void inputInfo() override;
    void displayInfo() const override;
    void displayNameAndID() const override;
    double getSalary() const override;
    Worker* clone() const override;
};
