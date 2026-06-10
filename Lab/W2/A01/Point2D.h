#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Point2D {
private:
    int x;
    int y;

public:
    // 5 Constructors
    Point2D();                              // Default constructor
    Point2D(int x);                         // Constructor with x only
    Point2D(int x, int y);                  // Constructor with x and y
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
    
    // Only needed for Triangle's area/centroid calculations
    int getX() const;
    int getY() const;
};
