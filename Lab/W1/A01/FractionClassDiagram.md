classDiagram
    class Fraction {
        -int num
        -int denom
        +Fraction()
        +Fraction(int n, int d)
        +Fraction(Fraction other)
        +input() void
        +display() void
        +add(Fraction b) void
        +subtract(Fraction b) void
        +divide(Fraction b) void
        +multiply(Fraction b) void
        +reduce() void
        +compare(Fraction b) bool
        +isPositive() bool
        +isNegative() bool
        +isZero() bool
    }