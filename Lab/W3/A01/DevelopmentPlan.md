# A01 — Fraction Class Development Plan

## Requirements Analysis

Implement a Fraction class supporting all operators demonstrated in the provided main.cpp:

| Category | Operators |
|----------|-----------|
| Constructors | Default (0/1), parameterized (n/d), copy |
| Assignment | `=` |
| Binary arithmetic | `+`, `-`, `*`, `/` |
| Mixed (int on either side) | `f+3`, `-7+f`, `7*f`, `f-6` |
| Comparison | `==`, `!=`, `>`, `>=`, `<`, `<=` |
| Compound assignment | `+=`, `-=`, `*=`, `/=` |
| Increment/Decrement | prefix `++f`, `--f`; postfix `f++`, `f--` |
| Stream output | `<<` |
| Type conversion | `(float)` cast |

## Design Decisions

### Representation
- `int num, den` — numerator and denominator
- Denominator is always positive after normalization (sign stored in numerator)
- Fractions are stored in reduced form after construction

### Normalization (reduce)
1. If denominator is negative, flip both signs so denominator is always positive
2. Divide numerator and denominator by their GCD

### GCD
- Euclidean algorithm on absolute values

### Arithmetic
- All binary operators (`+`, `-`, `*`, `/`) return a new `Fraction` by value (freshly reduced via constructor)
- Mixed int-on-right handled by a converting constructor: `Fraction(int n = 0, int d = 1)` with default `d = 1` — `3` implicitly converts to `Fraction(3, 1)` so `f + 3` compiles
- Mixed int-on-left needs free friend functions since `int` has no `operator+` overloaded for Fraction: `-7 + f` → friend converts `7` to `Fraction(7, 1)` then calls binary `+`

### Zero Denominator Protection
- The constructor `Fraction(int n, int d)` clamps `d == 0` → `den = 1` with `std::cerr` warning
- `reduce()` will never encounter a zero denominator

### Comparison
- Cross-multiply: `a/b > c/d` ⇔ `a*d > c*b`

### Compound Assignment
- Implemented as `*this = *this op other; return *this;`

### Increment/Decrement
- Prefix: modify and return reference
- Postfix: save copy, modify, return saved copy (by value)

### Cast to float
- `explicit operator float() const` — requires explicit cast `(float)f`

## File Structure

```
Lab/W3/A01/
├── Fraction.h        — Class declaration (all operator prototypes)
├── Fraction.cpp      — Implementation of all methods
├── Main.cpp          — Provided test code (unmodified)
└── DevelopmentPlan.md — This file
```

## Testing

Compile with:
```
g++ -std=c++11 Fraction.cpp Main.cpp -o Fraction.exe
```

Run `Fraction.exe`. No runtime errors or assertions should fail. All operator overloads resolve correctly, including mixed int-Fraction expressions and prefix/postfix increment/decrement.
