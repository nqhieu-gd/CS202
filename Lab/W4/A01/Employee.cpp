#include "Employee.h"
#include <sstream>

Employee::Employee() : hireDate() {}

Employee::Employee(const std::string& id, const std::string& name, const Date& date, const std::string& addr)
    : empId(id), fullName(name), hireDate(date), address(addr) {}

Employee::Employee(const Employee& other)
    : empId(other.empId), fullName(other.fullName), hireDate(other.hireDate), address(other.address) {}

Employee::Employee(const std::string& id, const Date& date)
    : empId(id), fullName(""), hireDate(date), address("") {}

Employee::Employee(const std::string& data) {
    size_t p1 = data.find(" || ");
    size_t p2 = data.find(" || ", p1 + 4);
    size_t p3 = data.find(" || ", p2 + 4);
    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos) {
        std::cerr << "Error: invalid Employee string format: " << data << std::endl;
        return;
    }
    empId = data.substr(0, p1);
    fullName = data.substr(p1 + 4, p2 - p1 - 4);
    address = data.substr(p3 + 4);
    std::string datePart = data.substr(p2 + 4, p3 - p2 - 4);
    int d, m, y;
    char s1, s2;
    std::istringstream(datePart) >> d >> s1 >> m >> s2 >> y;
    hireDate = Date(d, m, y);
}

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

void Employee::displayInfo() const {
    std::cout << "ID: " << empId << std::endl;
    std::cout << "Name: " << fullName << std::endl;
    std::cout << "Hire Date: ";
    hireDate.display();
    std::cout << std::endl;
    std::cout << "Address: " << address << std::endl;
}
