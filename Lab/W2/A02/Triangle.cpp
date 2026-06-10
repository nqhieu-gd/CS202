#include "Triangle.h"
#include <cmath>
#include <sstream>

// 1. Default constructor - creates triangle at origin
Triangle::Triangle() : A(0, 0), B(1, 0), C(0, 1) {
    cout << "Triangle::Default constructor" << endl;
}

// 2. Constructor with point A and zoom ratio (B and C default offset by ratio)
Triangle::Triangle(const Point2D& A, float ratio) : A(A), B(A.getX() + ratio, A.getY()), C(A.getX(), A.getY() + ratio) {
    cout << "Triangle::Constructor(Point2D A, float ratio)" << endl;
}

// 3. Constructor with 3 points
Triangle::Triangle(const Point2D& A, const Point2D& B, const Point2D& C) : A(A), B(B), C(C) {
    cout << "Triangle::Constructor(Point2D A, B, C)" << endl;
}

// 4. Copy constructor
Triangle::Triangle(const Triangle& other) : A(other.A), B(other.B), C(other.C) {
    cout << "Triangle::Copy constructor" << endl;
}

// 5. Constructor from string "x1,y1;x2,y2;x3,y3"
Triangle::Triangle(string s) {
    cout << "Triangle::Constructor(string s)" << endl;
    
    // Parse string format "x1,y1;x2,y2;x3,y3"
    size_t semi1 = s.find(';');
    size_t semi2 = s.find(';', semi1 + 1);
    
    if (semi1 != string::npos && semi2 != string::npos) {
        string sA = s.substr(0, semi1);
        string sB = s.substr(semi1 + 1, semi2 - semi1 - 1);
        string sC = s.substr(semi2 + 1);
        
        A = Point2D(sA);
        B = Point2D(sB);
        C = Point2D(sC);
    } else {
        A = Point2D(0, 0);
        B = Point2D(1, 0);
        C = Point2D(0, 1);
    }
}

// Destructor
Triangle::~Triangle() {
    cout << "Triangle::Destructor" << endl;
}

// Input method
void Triangle::input() {
    cout << "Enter point A:" << endl;
    A.input();
    cout << "Enter point B:" << endl;
    B.input();
    cout << "Enter point C:" << endl;
    C.input();
}

// Display method
void Triangle::display() const {
    cout << "Triangle: A";
    A.display();
    cout << " B";
    B.display();
    cout << " C";
    C.display();
    cout << endl;
}

// Check if triangle is valid (triangle inequality)
bool Triangle::isValid() const {
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);
    
    return (a + b > c) && (b + c > a) && (a + c > b);
}

// Get triangle type
string Triangle::getType() const {
    if (!isValid()) return "Invalid";
    
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);
    
    const double EPSILON = 0.0001;
    
    // Check equilateral
    if (fabs(a - b) < EPSILON && fabs(b - c) < EPSILON) {
        return "Equilateral";
    }
    
    // Check right triangle
    bool isRight = (fabs(a*a + b*b - c*c) < EPSILON) ||
                   (fabs(b*b + c*c - a*a) < EPSILON) ||
                   (fabs(a*a + c*c - b*b) < EPSILON);
    
    // Check isosceles
    bool isIsosceles = (fabs(a - b) < EPSILON) ||
                       (fabs(b - c) < EPSILON) ||
                       (fabs(a - c) < EPSILON);
    
    if (isRight && isIsosceles) return "Isosceles Right";
    if (isRight) return "Right";
    if (isIsosceles) return "Isosceles";
    
    return "Scalene";
}

// Calculate perimeter
double Triangle::perimeter() const {
    double a = B.distance(C);
    double b = A.distance(C);
    double c = A.distance(B);
    return a + b + c;
}

// Calculate area using cross product
double Triangle::area() const {
    float x1 = A.getX(), y1 = A.getY();
    float x2 = B.getX(), y2 = B.getY();
    float x3 = C.getX(), y3 = C.getY();
    
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Calculate centroid (center of mass)
Point2D Triangle::centroid() const {
    float cx = (A.getX() + B.getX() + C.getX()) / 3;
    float cy = (A.getY() + B.getY() + C.getY()) / 3;
    return Point2D(cx, cy);
}

// toString method: returns string "x1,y1;x2,y2;x3,y3"
string Triangle::toString() const {
    stringstream ss;
    ss << A.toString() << ";" << B.toString() << ";" << C.toString();
    return ss.str();
}

// clone method: creates a new Triangle with same values
Triangle Triangle::clone() const {
    return Triangle(A, B, C);
}
