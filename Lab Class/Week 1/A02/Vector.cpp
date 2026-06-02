#include "Coordinator.h"
#include <iostream>

Vector::Vector() : x(0), y(0) {}

Vector::Vector(Point A, Point B) {
    Vector temp = A.toVector(B);
    x = temp.x;
    y = temp.y;
}

void Vector::add(Vector b) {
    x += b.x;
    y += b.y;
}

double Vector::dotProduct(Vector b) {
    return x*b.x + y*b.y;
}

double Vector::crossProduct(Vector b) {
    return x*b.y - y*b.x;
}