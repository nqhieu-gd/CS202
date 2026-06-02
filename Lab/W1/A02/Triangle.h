#pragma once
#include "Coordinator.h"

class Triangle {
private:

    Point A;
    Point B;
    Point C;

public:

    Triangle();
    Triangle(Point A, Point B, Point C);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);

    void input();

    void display();

    bool isValid();

    int type();

    void outputType();

    double perimeter();

    double area();

    Point centerG();
};