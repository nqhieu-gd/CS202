#include "Point2D.h"

int main() {
    cout << "=== Testing Point2D Constructors ===" << endl << endl;

    // Test 1: Default constructor
    cout << "1. Creating p1 with default constructor:" << endl;
    Point2D p1;
    p1.display();
    cout << "toString: " << p1.toString() << endl << endl;

    // Test 2: Constructor with x only
    cout << "2. Creating p2 with x=5:" << endl;
    Point2D p2(5);
    p2.display();
    cout << "toString: " << p2.toString() << endl << endl;

    // Test 3: Constructor with x and y
    cout << "3. Creating p3 with x=15, y=-2:" << endl;
    Point2D p3(15, -2);
    p3.display();
    cout << "toString: " << p3.toString() << endl << endl;

    // Test 4: Copy constructor
    cout << "4. Creating p4 as copy of p3:" << endl;
    Point2D p4(p3);
    p4.display();
    cout << "toString: " << p4.toString() << endl << endl;

    // Test 5: Constructor from string
    cout << "5. Creating p5 from string \"10,20\":" << endl;
    Point2D p5("10,20");
    p5.display();
    cout << "toString: " << p5.toString() << endl << endl;

    // Test 6: clone() method
    cout << "6. Cloning p3:" << endl;
    Point2D p6 = p3.clone();
    p6.display();
    cout << "toString: " << p6.toString() << endl << endl;

    // Test 7: distance calculation
    cout << "7. Distance between p3 and p5:" << endl;
    cout << "Distance: " << p3.distance(p5) << endl << endl;

    cout << "=== Program ending (destructors will be called) ===" << endl;

    return 0;
}
