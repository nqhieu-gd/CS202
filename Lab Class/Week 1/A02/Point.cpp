#include "Coordinator.h"
#include <iostream>
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

void Point::input() {
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
}

void Point::display() {
    std::cout << '(' << x << ", " << y << ")\n";
}

double Point::distance(Point b) {
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

double Point::disToOx() {
    return abs(y);
}

double Point::disToOy() {
    return abs(x);
}

bool Point::isTheSame(Point B) {
    return (x == B.x) && (y == B.y);
}

Vector Point::toVector(Point B) {
    Vector v;
    v.x = B.x - x;
    v.y = B.y - y;
    return v;
}