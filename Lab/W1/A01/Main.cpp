#include "Fraction.h"
#include <iostream>

int main() {
    Fraction a(1, 2);
    Fraction b(3, 4);
    // Fraction a;
    // Fraction b;
    std::cout << "a: \n";
    // a.input();
    a.display();
    std::cout << "b: \n";
    // b.input();
    b.display();
    Fraction c(a);

    c.add(b);
    std::cout << "a + b: ";
    c.display();
    c = a;

    c.subtract(b);
    std::cout << "a - b: ";
    c.display();
    c = a;

    try {
        c.divide(b);
        std::cout << "a / b: ";
        c.display();
        c = a;
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    c.multiply(b);
    std::cout << "a * b: ";
    c.display();
    c = a;

    if (c.isPositive()) {
        std::cout << "a is positive\n";
    }
    else if (c.isNegative()) {
        std::cout << "a is negative\n";
    }
    else if (c.isZero()) {
        std::cout << "a is zero\n";
    }

    return 0;
}