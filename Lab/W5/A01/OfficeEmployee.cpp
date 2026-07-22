#include "OfficeEmployee.h"
#include <sstream>

OfficeEmployee::OfficeEmployee() : Employee(), workingDays(0) {}

OfficeEmployee::OfficeEmployee(const std::string& id, const std::string& name, const Date& date, const std::string& addr, int days) : Employee(id, name, date, addr), workingDays(days) {}

OfficeEmployee::OfficeEmployee(const OfficeEmployee& other) : Employee(other), workingDays(other.workingDays) {}

OfficeEmployee::OfficeEmployee(const std::string& id, const Date& date, int days) : Employee(id, date), workingDays(days) {}

OfficeEmployee::OfficeEmployee(const std::string& data) : Employee() {
    size_t p1 = data.find(" || ");
    size_t p2 = data.find(" || ", p1 + 4);
    size_t p3 = data.find(" || ", p2 + 4);
    size_t p4 = data.find(" || ", p3 + 4);
    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos || p4 == std::string::npos) {
        std::cerr << "Error: invalid OfficeEmployee string format: " << data << std::endl;
        return;
    }
    empId = data.substr(0, p1);
    fullName = data.substr(p1 + 4, p2 - p1 - 4);
    address = data.substr(p3 + 4, p4 - p3 - 4);
    std::string datePart = data.substr(p2 + 4, p3 - p2 - 4);
    int d, m, y;
    char s1, s2;
    std::istringstream(datePart) >> d >> s1 >> m >> s2 >> y;
    hireDate = Date(d, m, y);
    workingDays = std::stoi(data.substr(p4 + 4));
}

OfficeEmployee::~OfficeEmployee() {}

void OfficeEmployee::inputInfo() {
    Employee::inputInfo();
    std::cout << "Enter number of working days: ";
    std::cin >> workingDays;
    std::cin.ignore();
}

void OfficeEmployee::displayInfo() const {
    Employee::displayInfo();
    std::cout << "Working Days: " << workingDays << std::endl;
    std::cout << "Salary: " << getSalary() << " VND" << std::endl;
}

void OfficeEmployee::displayNameAndID() const {
    std::cout << "Office Employee - ";
    Employee::displayNameAndID();
}

double OfficeEmployee::getSalary() const {
    return workingDays * 300000.0;
}

OfficeEmployee* OfficeEmployee::clone() const {
    return new OfficeEmployee(*this);
}