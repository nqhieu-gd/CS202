#include "Worker.h"
#include <sstream>

Worker::Worker() : Employee(), producedItems(0) {}

Worker::Worker(const std::string& id, const std::string& name, const Date& date, const std::string& addr, int items) : Employee(id, name, date, addr), producedItems(items) {}

Worker::Worker(const Worker& other) : Employee(other), producedItems(other.producedItems) {}

Worker::Worker(const std::string& id, const Date& date, int items) : Employee(id, date), producedItems(items) {}

Worker::Worker(const std::string& data) : Employee() {
    size_t p1 = data.find(" || ");
    size_t p2 = data.find(" || ", p1 + 4);
    size_t p3 = data.find(" || ", p2 + 4);
    size_t p4 = data.find(" || ", p3 + 4);
    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos || p4 == std::string::npos) {
        std::cerr << "Error: invalid Worker string format: " << data << std::endl;
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
    producedItems = std::stoi(data.substr(p4 + 4));
}

Worker::~Worker() {}

void Worker::inputInfo() {
    Employee::inputInfo();
    std::cout << "Enter number of produced items: ";
    std::cin >> producedItems;
    std::cin.ignore();
}

void Worker::displayInfo() const {
    Employee::displayInfo();
    std::cout << "Produced Items: " << producedItems << std::endl;
    std::cout << "Salary: " << getSalary() << " VND" << std::endl;
}

void Worker::displayNameAndID() const {
    std::cout << "Worker - ";
    Employee::displayNameAndID();
}

double Worker::getSalary() const {
    return producedItems * 5000.0;
}

Worker* Worker::clone() const {
    return new Worker(*this);
}