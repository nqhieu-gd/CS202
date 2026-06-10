#include "Point2D.h"
#include <cmath>

// 1. Default constructor
Point2D::Point2D() : x(0), y(0) {
    // Silent for Triangle usage
}

// 2. Constructor with x only (y defaults to 0)
Point2D::Point2D(float x) : x(x), y(0) {
}

// 3. Constructor with x and y
Point2D::Point2D(float x, float y) : x(x), y(y) {
}

// 4. Copy constructor
Point2D::Point2D(const Point2D& other) : x(other.x), y(other.y) {
}

// 5. Constructor from string "x,y"
Point2D::Point2D(string s) {
    size_t commaPos = s.find(',');
    if (commaPos != string::npos) {
        x = stof(s.substr(0, commaPos));
        y = stof(s.substr(commaPos + 1));
    } else {
        x = 0;
        y = 0;
    }
}

// Destructor
Point2D::~Point2D() {
    // Silent for Triangle usage
}

// Getters
float Point2D::getX() const {
    return x;
}

float Point2D::getY() const {
    return y;
}

// Input method
void Point2D::input() {
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}

// Display method
void Point2D::display() const {
    cout << "(" << x << ", " << y << ")";
}

// Distance to another point
double Point2D::distance(const Point2D& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

// toString method: returns string "x,y"
string Point2D::toString() const {
    stringstream ss;
    ss << x << "," << y;
    return ss.str();
}

// clone method: creates a new Point2D with same values
Point2D Point2D::clone() const {
    return Point2D(x, y);
}
