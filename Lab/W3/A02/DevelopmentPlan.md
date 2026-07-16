# A02 — Date Class Development Plan

## Requirements Analysis

Implement a Date class supporting all operators demonstrated in the provided `main.cpp`:

| Category | Operators |
|----------|-----------|
| Constructors | Default (system date), year-only (1/1/y), year+month (1/m/y), full (d/m/y), copy |
| Assignment | `=` |
| Day navigation | `Tomorrow()`, `Yesterday()` |
| Comparison | `==`, `!=`, `>`, `>=`, `<`, `<=` |
| Date + int | `d+N`, `d-N` |
| Compound | `+=`, `-=` |
| Inc/Dec | prefix `++d`, `--d`; postfix `d++`, `d--` |
| Stream | `<<`, `>>` |
| Type conversion | `(int)` — day of year; `(long)` — days since 1/1/1 |

## Design Decisions

### The Bridge (Core Idea)
Date arithmetic in human form (DD/MM/YYYY) is complex. Solution: convert to a single day-number, do math, convert back.

```
dateToDays(d, m, y) → long dayNumber
daysToDate(n)       → (d, m, y)
```

Every operator that changes a date follows this pattern:
```
Tomorrow  = dateToDays() + 1  →  daysToDate()
d + N     = dateToDays() + N  →  daysToDate()
(long)    = dateToDays()       (already a day number)
(int)     = cumulative month table (day of year)
```

### Day-Number Formula (O(1), no loops)
```
days before year y  =  (y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400
```
This single formula replaces iterating over every year.

### Static Lookup Tables
```cpp
const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int cumDays[]   = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
```
`cumDays[m]` gives total days before month `m` in a non-leap year. Used by `dateToDays`, `daysToDate`, and `operator int()`.

### Formula Reuse via dateToDays(0, 1, y)
`dateToDays(0, 1, y)` = Dec 31 of year y-1 = exact "days before year y" value. Reusing this in `daysToDate` eliminates duplicating the leap-year formula.

### Comparison
- `==`: all three fields equal
- `<` / `>`: compare year, then month, then day
- `!=`, `<=`, `>=`: derived from `==`, `<`, `>`

### Prefix vs Postfix
- Prefix: no dummy parameter, returns `Date&` (the new value)
- Postfix: dummy `int` parameter, saves copy, returns `Date` (the old value)

### Mixed Int Arithmetic
Not needed — all arithmetic is `Date +/- int`. The int is always on the right side.

### Stream I/O
- `<<` formats as `DD/MM/YYYY` with leading zeros
- `>>` reads `DD/MM/YYYY` format
- Both are `friend` functions (left operand is the stream, not Date)

### Type Conversion
- `(int)d` — day of year (Jan 1 = 1, Feb 1 = 32, etc.)
- `(long)d` — days since 1/1/1 (Jan 1 year 1 = 1)

### Edge Cases Handled
- `n < 1` in `daysToDate` → error message, clamp to 1/1/1
- Invalid constructor input (year < 1, month out of range, invalid day) → error message, sensible fallback
- Leap year Feb 29 accepted, Feb 30 rejected

## Student-Caught Issues (Self-Review Checkpoints)

These are problems the student identified and guided me to fix — demonstrating understanding before committing to further work.

| # | Issue | What was wrong | Why it matters |
|---|-------|---------------|----------------|
| 1 | **Main.cpp includes** | Used `using namespace std;` and redundant `#include <iostream>` | Hides where names come from; bad practice for learners. Fixed to use explicit `std::` prefix and rely on `Date.h` providing `<iostream>`. |
| 2 | **O(Y) loops in date conversion** | `dateToDays` looped from year 1 to Y, `daysToDate` looped year by year | For year 1 billion, that's 1 billion iterations — unusable. Fixed to O(1) using leap-year counting formula: `(y-1)/4 - (y-1)/100 + (y-1)/400`. |
| 3 | **Branch chains for month lengths** | `daysInMonth` used if-else chains; `operator int()` looped month by month | Hard to read, compiler can't optimize well. Replaced both with static lookup tables `monthDays[]` and `cumDays[]`. |
| 4 | **Shared arrays duplicated 3×** | `cumDays[]` declared separately in `dateToDays`, `daysToDate`, and `operator int()` | Three copies in memory. Consolidated into file-scope `const` arrays at top of Date.cpp — one copy, all functions share. |
| 5 | **Anonymous namespace noise** | Arrays wrapped in `namespace { }` | Redundant: `const` at file scope already has internal linkage in C++. Removed. |
| 6 | **Silent clamp on invalid date** | `daysToDate(n < 1)` silently clamped to 1/1/1 | User thinks code is buggy. Added `std::cerr` error message "Date does not accept year before 1" before clamping. |
| 7 | **No constructor validation** | `Date(0)`, `Date(2024, 13)`, `Date(2024, 2, 30)` accepted silently | Creates invalid internal state. Added validation with error messages and sensible fallback values. |
| 8 | **No input validation in `>>`** | `cin >> d4` accepted any three numbers with slashes | Garbage in = garbage out. Added day/month/year range check with error message. |
| 9 | **Duplicated leap-year formula 4×** | The formula `(y-1)*365 + ...` appeared in initial calc, both while loops, and inner backward loop | Mend any one, miss another → silent bug. Fixed by reusing `dateToDays(0, 1, y)` everywhere. |
| 10 | **Convoluted leap logic in month search** | `(leap && m > 1 ? 1 : 0)` and `(leap && m > 2 ? 1 : 0)` in same math | Hard to verify correctness. Fixed with single `afterFeb` flag computed once. |

## File Structure

```
Lab/W3/A02/
├── Date.h              — Class declaration (all operator prototypes)
├── Date.cpp            — Implementation of all methods
├── Main.cpp            — Provided test code (unmodified)
└── DevelopmentPlan.md  — This file
```

## Testing

Compile with:
```
g++ Date.cpp Main.cpp -o Date.exe
```

Run `Date.exe` with piped input for `cin >> d4`:
```
echo "15/03/2025" | ./Date.exe
```

Expected output:
```
01010102/01/20122739325
```
(Six comparison results concatenated, then d3, (int)d3, (long)d4 — all without separators, matching the original `main.cpp` style.)
