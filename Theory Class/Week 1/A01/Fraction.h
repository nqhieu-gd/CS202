#pragma once

class Fraction {
private:
    int num;
    int denom;

    Fraction();
    Fraction(int n, int d);
    void operator=(const Fraction& o);
    Fraction(Fraction& other);

public:
    void display();

    void add(Fraction b);

    void subtract(Fraction b);

    void divide(Fraction b);

    void multiply(Fraction b);

    void reduce();

    bool compare(Fraction b);

    bool isPositive();

    bool isNegative();

    bool isZero();
};