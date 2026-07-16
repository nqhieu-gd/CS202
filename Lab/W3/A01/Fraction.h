#pragma once
#include <iostream>

class Fraction {
private:
    int num;
    int den;

    void reduce();
    static int gcd(int a, int b);

public:
    Fraction(int n = 0, int d = 1);
    Fraction(const Fraction& other);
    ~Fraction();

    Fraction& operator=(const Fraction& other);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    Fraction operator++(int);
    Fraction& operator++();
    Fraction operator--(int);
    Fraction& operator--();

    explicit operator float() const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend Fraction operator+(int lhs, const Fraction& rhs);
    friend Fraction operator-(int lhs, const Fraction& rhs);
    friend Fraction operator*(int lhs, const Fraction& rhs);
    friend Fraction operator/(int lhs, const Fraction& rhs);
};
