#pragma once

class Fraction {
private:

    int num;
    int denom;

public:

    Fraction();
    Fraction(int n, int d);
    Fraction(const Fraction& other);
    Fraction& operator=(const Fraction& other);

    void input();

    void display();

    void add(Fraction b);

    void subtract(Fraction b);

    void divide(Fraction b);

    void multiply(Fraction b);

    void revert();

    void reduce();

    bool compare(Fraction b);

    bool isPositive();

    bool isNegative();

    bool isZero();
};