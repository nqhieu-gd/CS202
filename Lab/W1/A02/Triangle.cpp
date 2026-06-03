#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : A(), B(), C() {}

Triangle::Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) {
    if (!isValid()) {
        std::cerr << "Invalid triangle! Setting to default.\n";
        A = Point();
        B = Point();
        C = Point();
    }
}

Triangle& Triangle::operator=(const Triangle& other) {
    A = other.A;
    B = other.B;
    C = other.C;
    return *this;
}

void Triangle::input() {
    std::cout << "Enter point A:\n";
    A.input();
    std::cout << "Enter point B:\n";
    B.input();
    std::cout << "Enter point C:\n";
    C.input();
}

void Triangle::display() {
    std::cout << "Triangle vertices are:\n";
    std::cout << "Point A: ";
    A.display();
    std::cout << "Point B: ";
    B.display();
    std::cout << "Point C: ";
    C.display();
}

bool Triangle::isValid() {
    return (A.distance(B) + B.distance(C) > A.distance(C)) && (A.distance(B) + A.distance(C) > B.distance(C)) && (B.distance(C) + A.distance(C) > A.distance(B));
}

int Triangle::type() {
    double AB = A.distance(B);
    double BC = B.distance(C);
    double CA = C.distance(A);
    int res = 0;
    if (AB == BC && BC == CA) {
        res += 2;
    }
    else if (AB == BC || BC == CA || CA == AB) {
        res += 1;
    }
    if (pow(AB, 2) + pow(BC, 2) - pow(CA, 2) < 0.000001 || pow(BC, 2) + pow(CA, 2) - pow(AB, 2) < 0.000001 || pow(CA, 2) + pow(AB, 2) - pow(BC, 2) < 0.000001) {
        res += 10;
    }
    return res;
}

void Triangle::outputType() {
    int t = type();
    if (t == 2) {
        std::cout << "Equilateral triangle\n";
    }
    else if (t == 11) {
        std::cout << "Isosceles right triangle\n";
    }
    else if (t == 10) {
        std::cout << "Right triangle\n";
    }
    else if (t == 1) {
        std::cout << "Isosceles triangle\n";
    }
    else {
        std::cout << "Scalene triangle\n";
    }
}

double Triangle::perimeter() {
    return A.distance(B) + B.distance(C) + C.distance(A);
}

double Triangle::area() {
    return std::abs(A.toVector(B).crossProduct(A.toVector(C)) / 2.0);
}

Point Triangle::centerG() {
    Vector vt;
    vt.add(A.toVector(Point(0, 0)));
    vt.add(B.toVector(Point(0, 0)));
    vt.add(C.toVector(Point(0, 0)));
    return Point(vt.x / 3.0, vt.y / 3.0);
}