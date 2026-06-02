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
        reduce();
    }
}

Fraction::Fraction(const Fraction& other) : num(other.num), denom(other.denom) {}

Fraction& Fraction::operator=(const Fraction& other) {
    num = other.num;
    denom = other.denom;
    return *this;
}

void Fraction::input() {
    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> denom;
    if (denom == 0) {
        std::cerr << "Denominator can not be zero. Setting to 0/1." << std::endl;
        num = 0;
        denom = 1;
    }
    reduce();
}

void Fraction::display() {
    std::cout << num << '/' << denom << '\n';
}

void Fraction::add(Fraction b) {
    num = num*b.denom + denom*b.num;
    denom = denom*b.denom;
    reduce();
}

void Fraction::subtract(Fraction b) {
    num = num*b.denom - denom*b.num;
    denom = denom*b.denom;
    reduce();
}

void Fraction::divide(Fraction b) {
    if (b.num == 0) {
        throw "Division by zero!";
    }
    num = num*b.denom;
    denom = denom*b.num;
    reduce();
}

void Fraction::multiply(Fraction b) {
    num = num*b.num;
    denom = denom*b.denom;
    reduce();
}

void Fraction::revert() {
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
}

void Fraction::reduce() {
    if (num % denom == 0) {
        num /= denom;
        denom /= denom;
        revert();
        return;
    }
    else if (denom % num == 0) {
        denom /= num;
        num /= num;
        revert();
        return;
    }
    int a = num;
    while (num % a != 0 || denom % a != 0) {
        if (num % a != 0) a = num % a;
        else if (denom % a != 0) a = denom % a;
    }
    num = num/a;
    denom = denom/a;
    revert();
}

bool Fraction::compare(Fraction b) {
    if (num*b.denom - denom*b.num >= 0) return true;
    else return false;
}

bool Fraction::isPositive() {
    return num > 0;
}

bool Fraction::isNegative() {
    return num < 0;
}

bool Fraction::isZero() {
    return num == 0;
}