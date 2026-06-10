#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Point2D {
private:
    float x;
    float y;

public:
    // 5 Constructors
    Point2D();                              // Default constructor
    Point2D(float x);                       // Constructor with x only
    Point2D(float x, float y);              // Constructor with x and y
    Point2D(const Point2D& other);          // Copy constructor
    Point2D(string s);                      // Constructor from string "x,y"

    // Destructor
    ~Point2D();

    // Methods
    void input();
    void display() const;
    double distance(const Point2D& other) const;
    string toString() const;
    Point2D clone() const;
    
    // Only for Triangle's internal calculations
    float getX() const;
    float getY() const;
};
