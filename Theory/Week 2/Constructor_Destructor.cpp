#include <iostream>

class Fraction {
private:
    int num;
    int denom;

    Fraction() {
        num = 0;
        denom = 1;
    }
    Fraction(int n, int d) {
        if (d == 0) {
            std::cout << "Denominator cannot be zero." << std::endl;
        }
        else {
            num = n;
            denom = d;
        }
    }
    void operator=(const Fraction& o) {
        num = o.num;
        denom = o.denom;
    }

public:
    void display() {
        std::cout << num << "/" << denom << std::endl;
    }

    void add(Fraction b) {
        if (b.denom == 0) {
            std::cout << "Invalid fraction." << std::endl;
            return;
        }
        num = num * b.denom + b.num * denom;
        denom = denom * b.denom;
    }

    void divide(Fraction b) {
        if (b.denom == 0 || b.num == 0) {
            std::cout << "Invalid division fraction." << std::endl;
            return;
        }
        num = num * b.denom;
        denom = denom * b.num;
    }
};