#include "Triangle.h"

int main() {
    cout << "=== Testing Triangle Constructors ===" << endl << endl;

    // Test 1: Default constructor
    cout << "1. Creating t1 with default constructor:" << endl;
    Triangle t1;
    t1.display();
    cout << "toString: " << t1.toString() << endl;
    cout << "Type: " << t1.getType() << endl;
    cout << "Perimeter: " << t1.perimeter() << endl;
    cout << "Area: " << t1.area() << endl << endl;

    // Test 2: Constructor with point A only (default ratio = 1)
    cout << "2. Creating t2 with point A(2,3):" << endl;
    Point2D pA(2, 3);
    Triangle t2(pA);
    t2.display();
    cout << "toString: " << t2.toString() << endl << endl;

    // Test 2b: Constructor with point A and zoom ratio 2
    cout << "2b. Creating t2b with point A(2,3) and ratio 2:" << endl;
    Triangle t2b(pA, 2.0f);
    t2b.display();
    cout << "toString: " << t2b.toString() << endl;
    cout << "Area: " << t2b.area() << " (area scales by ratio^2 = 0.5 * 4 = 2)" << endl << endl;

    // Test 3: Constructor with 3 points
    cout << "3. Creating t3 with A(0,0), B(3,0), C(0,4):" << endl;
    Point2D p1(0, 0);
    Point2D p2(3, 0);
    Point2D p3(0, 4);
    Triangle t3(p1, p2, p3);
    t3.display();
    cout << "toString: " << t3.toString() << endl;
    cout << "Type: " << t3.getType() << endl;
    cout << "Perimeter: " << t3.perimeter() << endl;
    cout << "Area: " << t3.area() << endl;
    Point2D center = t3.centroid();
    cout << "Centroid: ";
    center.display();
    cout << endl << endl;

    // Test 4: Copy constructor
    cout << "4. Creating t4 as copy of t3:" << endl;
    Triangle t4(t3);
    t4.display();
    cout << "toString: " << t4.toString() << endl << endl;

    // Test 5: Constructor from string
    cout << "5. Creating t5 from string \"1,1;4,1;2,4\":" << endl;
    Triangle t5("1,1;4,1;2,4");
    t5.display();
    cout << "toString: " << t5.toString() << endl;
    cout << "Type: " << t5.getType() << endl << endl;

    // Test 6: clone() method
    cout << "6. Cloning t3:" << endl;
    Triangle t6 = t3.clone();
    t6.display();
    cout << "toString: " << t6.toString() << endl << endl;

    cout << "=== Program ending (destructors will be called) ===" << endl;

    return 0;
}
