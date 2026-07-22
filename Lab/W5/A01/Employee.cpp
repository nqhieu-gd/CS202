#include "Employee.h"
#include <sstream>

Employee::Employee() : hireDate() {}

Employee::Employee(const std::string& id, const std::string& name, const Date& date, const std::string& addr)
    : empId(id), fullName(name), hireDate(date), address(addr) {}

Employee::Employee(const Employee& other)
    : empId(other.empId), fullName(other.fullName), hireDate(other.hireDate), address(other.address) {}

Employee::Employee(const std::string& id, const Date& date)
    : empId(id), fullName(""), hireDate(date), address("") {}

Employee::~Employee() {}

void Employee::inputInfo() {
    std::cout << "Enter employee ID: ";
    std::getline(std::cin, empId);
    std::cout << "Enter full name: ";
    std::getline(std::cin, fullName);
    int d, m, y;
    std::cout << "Enter hire date (dd mm yyyy): ";
    std::cin >> d >> m >> y;
    std::cin.ignore();
    hireDate = Date(d, m, y);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
}

void Employee::displayNameAndID() const {
    std::cout << "ID: " << empId << ", Name: " << fullName << std::endl;
}

void Employee::displayInfo() const {
    std::cout << "ID: " << empId << std::endl;
    std::cout << "Name: " << fullName << std::endl;
    std::cout << "Hire Date: ";
    hireDate.display();
    std::cout << std::endl;
    std::cout << "Address: " << address << std::endl;
}
