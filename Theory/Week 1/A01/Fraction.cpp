#include "Fraction.h"
#include <iostream>

Fraction::Fraction() : num(0), denom(1) {}
Fraction::Fraction(int n, int d) {
    if (d == 0) {
        std::cerr << "Denominator cannot be zero." << std::endl;
        num = 0;
        denom = 1;
    }
    else {
        num = n;
        denom = d;
    }
}
void Fraction::operator=(const Fraction& o) {
    num = o.num;
    denom = o.denom;
}
Fraction::Fraction(Fraction& other) : num(other.num), denom(other.denom) {}

void Fraction::display();

void Fraction::add(Fraction b);

void Fraction::subtract(Fraction b);

void Fraction::divide(Fraction b);

void Fraction::multiply(Fraction b);

void Fraction::reduce();

bool Fraction::compare(Fraction b);

bool Fraction::isPositive();

bool Fraction::isNegative();

bool Fraction::isZero();