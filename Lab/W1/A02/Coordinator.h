#pragma once

struct Vector;

class Point {
private:

    double x;
    double y;

public:

    Point();
    Point(double x, double y);
    Point(const Point& other);
    Point& operator=(const Point& other);

    void input();

    void display();

    double distance(Point b);

    double disToOx();

    double disToOy();

    bool isTheSame(Point B);

    Vector toVector(Point B);
};

struct Vector {
    double x;
    double y;

    Vector();
    Vector(Point A, Point B);

    double crossProduct(Vector v);

    double dotProduct(Vector v);

    void add(Vector v);
};