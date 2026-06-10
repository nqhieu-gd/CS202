#pragma once
#include "Point2D.h"
#include <string>
using namespace std;

class Triangle {
private:
    Point2D A;
    Point2D B;
    Point2D C;

public:
    // 5 Constructors
    Triangle();                                                 // Default constructor
    Triangle(const Point2D& A, float ratio = 1.0f);             // Constructor with point A + zoom ratio
    Triangle(const Point2D& A, const Point2D& B, const Point2D& C); // Constructor with 3 points
    Triangle(const Triangle& other);                            // Copy constructor
    Triangle(string s);                                         // Constructor from string "x1,y1;x2,y2;x3,y3"

    // Destructor
    ~Triangle();

    // Methods
    void input();
    void display() const;
    bool isValid() const;
    string getType() const;
    double perimeter() const;
    double area() const;
    Point2D centroid() const;
    string toString() const;
    Triangle clone() const;
};
