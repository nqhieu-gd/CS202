#pragma once

class Fraction {
private:
    int num;
    int denom;

    Fraction();
    Fraction(const Fraction& other);
    Fraction(const Fraction& other1, const Fraction& other2);
    void operator=(const Fraction& o);

public:
    void display();

    void add(const Fraction& b);

    void divide(const Fraction& b);
};