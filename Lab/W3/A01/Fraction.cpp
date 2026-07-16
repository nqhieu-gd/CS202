#include "Fraction.h"

int Fraction::gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void Fraction::reduce() {
    if (den == 0) return;
    if (den < 0) { num = -num; den = -den; }
    int g = gcd(num, den);
    if (g > 1) { num /= g; den /= g; }
}

Fraction::Fraction(int n, int d) : num(n), den(d == 0 ? 1 : d) {
    if (d == 0) std::cerr << "Error: Zero denominator, set to 1" << std::endl;
    reduce();
}

Fraction::Fraction(const Fraction& other) : num(other.num), den(other.den) {}

Fraction::~Fraction() {}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        num = other.num;
        den = other.den;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(num * other.den + other.num * den, den * other.den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(num * other.den - other.num * den, den * other.den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(num * other.num, den * other.den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.num == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fraction(0, 1);
    }
    return Fraction(num * other.den, den * other.num);
}

bool Fraction::operator==(const Fraction& other) const {
    return num == other.num && den == other.den;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator>(const Fraction& other) const {
    return num * other.den > other.num * den;
}

bool Fraction::operator>=(const Fraction& other) const {
    return *this > other || *this == other;
}

bool Fraction::operator<(const Fraction& other) const {
    return num * other.den < other.num * den;
}

bool Fraction::operator<=(const Fraction& other) const {
    return *this < other || *this == other;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction old = *this;
    *this = *this + Fraction(1, 1);
    return old;
}

Fraction& Fraction::operator++() {
    *this = *this + Fraction(1, 1);
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction old = *this;
    *this = *this - Fraction(1, 1);
    return old;
}

Fraction& Fraction::operator--() {
    *this = *this - Fraction(1, 1);
    return *this;
}

Fraction::operator float() const {
    return static_cast<float>(num) / den;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.num << "/" << f.den;
    return os;
}

Fraction operator+(int lhs, const Fraction& rhs) {
    return Fraction(lhs, 1) + rhs;
}

Fraction operator-(int lhs, const Fraction& rhs) {
    return Fraction(lhs, 1) - rhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    return Fraction(lhs, 1) * rhs;
}

Fraction operator/(int lhs, const Fraction& rhs) {
    return Fraction(lhs, 1) / rhs;
}
