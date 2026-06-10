#include "Point2D.h"
#include <cmath>

// 1. Default constructor
Point2D::Point2D() : x(0), y(0) {
    cout << "Point2D::Default constructor" << endl;
}

// 2. Constructor with x only (y defaults to 0)
Point2D::Point2D(int x) : x(x), y(0) {
    cout << "Point2D::Constructor(int x)" << endl;
}

// 3. Constructor with x and y
Point2D::Point2D(int x, int y) : x(x), y(y) {
    cout << "Point2D::Constructor(int x, int y)" << endl;
}

// 4. Copy constructor
Point2D::Point2D(const Point2D& other) : x(other.x), y(other.y) {
    cout << "Point2D::Copy constructor" << endl;
}

// 5. Constructor from string "x,y"
Point2D::Point2D(string s) {
    cout << "Point2D::Constructor(string s)" << endl;
    
    // Parse string format "x,y"
    size_t commaPos = s.find(',');
    if (commaPos != string::npos) {
        x = stoi(s.substr(0, commaPos));
        y = stoi(s.substr(commaPos + 1));
    } else {
        x = 0;
        y = 0;
    }
}

// Destructor
Point2D::~Point2D() {
    cout << "Point2D::Destructor" << endl;
}

// Getters (only for internal calculations)
int Point2D::getX() const {
    return x;
}

int Point2D::getY() const {
    return y;
}

// Input method
void Point2D::input() {
    cout << "Enter x: ";
    cin >> x;
    cout << "\nEnter y: ";
    cin >> y;
}

// Display method
void Point2D::display() const {
    cout << "Point(" << x << ", " << y << ")" << endl;
}

// Distance to another point
double Point2D::distance(const Point2D& other) const {
    int dx = x - other.x;
    int dy = y - other.y;
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
