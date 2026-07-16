# AI Proposal Report - CS202 Week 3 Assignments

## Student Information
- **Student**: Nguyen Quang Hieu - 25125043
- **Course**: CS202 - Programming Systems
- **Week**: Week 3

## W3 Assignment Overview

This proposal covers AI usage for Week 3 assignments:
- **A01**: Fraction Class — Operator Overloading
- **A02**: Date Class — Full Operator Overloading
- **A03**: IntArray Class — Dynamic Array Operator Overloading

Topic: **Operator Overloading** in C++ OOP

---

## AI Usage Declaration

### 1. What AI Did (Under My Direction)
- **A01**: Generated `Fraction.h` and `Fraction.cpp` implementing all operators from provided `main.cpp`
- **A02**: Generated `Date.h` and `Date.cpp` implementing the bridge conversion (dateToDays/daysToDate) and all operators
- **A03**: Generated `IntArray.h` and `IntArray.cpp` implementing dynamic array with operator overloading
- Created `DevelopmentPlan.md` for each assignment documenting design decisions

### 2. What I Directed / Piloted

#### A01 — Fraction
- Provided exact `main.cpp` with all operator calls — AI reverse-engineered every operator signature
- Caught and removed unnecessary `<cstdlib>` include (AI had used library `abs()` instead of inline absolute value)
- Caught missing division-by-zero guard in `operator/` — directed AI to add `cerr` error and `0/1` return
- Approved only after no extraneous dependencies and all edge cases handled

#### A02 — Date
- Noticed AI's original `Main.cpp` used `using namespace std;` which obscures name origins — directed change to explicit `std::` prefix
- Identified that `dateToDays` and `daysToDate` used O(Y) loops (year-by-year iteration) — directed rewrite to O(1) leap-year counting formula: `(y-1)/4 - (y-1)/100 + (y-1)/400`
- Pointed out branch chains in `daysInMonth` and month loops in `operator int()` — directed replacement with static lookup tables `monthDays[]` and `cumDays[]`
- Noticed `cumDays[]` duplicated in 3 separate functions — directed consolidation to single file-scope arrays
- Caught anonymous namespace around arrays as unnecessary (`const` already gives internal linkage) — directed removal
- Identified silent clamp on `n < 1` in `daysToDate` — directed to add `cerr` error message instead of hiding the bug
- Noticed constructors accepted invalid input silently (`Date(0)`, `Date(2024, 13)`, `Date(2024, 2, 30)`) — directed to add validation with error messages
- Noticed `operator>>` had no input validation — directed to add range checking
- Caught duplicated leap-year formula appearing 4 times — directed to reuse `dateToDays(0, 1, y)` everywhere
- Found convoluted month leap logic with `(leap && m > 1 ? 1 : 0)` and `(leap && m > 2 ? 1 : 0)` — directed to replace with single `afterFeb` flag

#### A03 — IntArray
- Noticed constructor allocated `new int[0]` for empty arrays — directed to guard with `if (n > 0)`
- Identified exception-unsafe `operator=` (delete before new could throw) — directed to allocate-first pattern (strong exception guarantee)
- Pointed out destructor leaves dangling pointer after `delete[]` — directed to set `data = nullptr`
- Asked for explanation of two-version `operator[]` (`int&` vs `int const`) — verified understanding of read/write semantics

### 3. What I Did Myself
- Analyzed each `main.cpp` to determine every operator overload needed
- Understood why `friend` functions are needed for stream operators (left operand is the stream, not the class)
- Understood prefix vs postfix distinction (dummy `int` parameter, reference vs value return)
- Knew the Rule of Three and why dynamic memory classes need destructor + copy constructor + copy assignment
- Made design calls: converting constructor for int-to-Fraction, explicit cast, reduction strategy, `afterFeb` flag
- Reviewed every line of generated code for correctness
- Caught every bug listed above — AI did not catch itself

---

## Key Design Decisions (All Mine)

| # | Decision | Rationale |
|---|----------|-----------|
| 1 | Stored in reduced form | `==` works by direct value comparison |
| 2 | Denominator always positive | Simplifies comparison and printing |
| 3 | Default argument `d = 1` | Enables int-on-right operations via implicit conversion |
| 4 | `friend` for int-on-left | `int` has no Fraction-aware operators |
| 5 | `explicit` float cast | Prevents accidental implicit conversion |
| 6 | O(1) leap-year formula | Year-by-year loop is O(Y) — unusable for large years |
| 7 | Static lookup arrays | Replace branch chains and month loops |
| 8 | Reuse `dateToDays(0, 1, y)` | Eliminates duplicated leap-year formula in 4 places |
| 9 | `afterFeb` flag | Single condition replaces duplicate leap logic |
| 10 | Allocate-first in `operator=` | If `new` throws, original data is preserved |
| 11 | Two-version `operator[]` | `int&` for writing, `int const` for reading on const objects |

---

## Academic Integrity
- AI generated initial code, but I directed which operators to implement and how
- I caught every bug listed above — AI did not catch itself
- Every operator overload, constructor, and cast is verified and understood by me
- I can explain and modify any part of the code independently

---

## Files Submitted

### A01 — Fraction Class
| File | Description |
|------|-------------|
| `Fraction.h` | Class declaration with all operator prototypes |
| `Fraction.cpp` | Implementation — arithmetic, comparison, inc/dec, cast, stream |
| `Main.cpp` | Provided test program (unmodified) |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A02 — Date Class
| File | Description |
|------|-------------|
| `Date.h` | Class declaration — all operator prototypes, static helpers |
| `Date.cpp` | Implementation — O(1) bridge conversion, 15 operators, validation |
| `Main.cpp` | Provided test program (unmodified) |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A03 — IntArray Class
| File | Description |
|------|-------------|
| `IntArray.h` | Class declaration — Rule of Three, operator[], int cast, stream |
| `IntArray.cpp` | Implementation — deep copy, exception-safe assignment, defensive patterns |
| `Main.cpp` | Provided test program (unmodified) |
| `DevelopmentPlan.md` | Design and prompting documentation |

---

## Conclusion

This proposal demonstrates responsible AI use for W3 across all three assignments. AI was used as a code generator under my direction. I provided the requirements, reviewed all output, caught every bug (no AI tool auto-corrected itself), and validated every operator overload. All design decisions — reduction strategy, the bridge conversion pattern, O(1) formula optimization, defensive memory management — were made by me, not the AI.
