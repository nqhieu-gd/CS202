# AI Proposal Report — CS202 Week 5 Assignments

## Student Information
- **Student**: Nguyen Quang Hieu - 25125043
- **Course**: CS202 - Programming Systems
- **Week**: Week 5

## W5 Assignment Overview

This proposal covers AI usage for Week 5 assignments:
- **A01**: Company Employee Management — Polymorphism with abstract base
- **A02**: Console Output Analysis — Constructor/destructor tracing
- **A03**: Console, Memory Issues, I/O Operators — Code analysis + fix
- **A04**: Prince and Princess — Polymorphic gate simulation
- **A05**: Python Polymorphism — Review
- **A06**: Java Polymorphism — Review

Topic: **Polymorphism** in C++ OOP

---

## AI Usage Declaration

**Declaration B: I did use AI for this homework.**

### 1. What AI Did (Under My Direction)
- Generated initial header and source files for A01 (Company, Employee, OfficeEmployee, Worker, Date), A03 (3.h, 3.cpp with I/O operators), A04 (Castle, Gatekeeper hierarchy)
- Created DevelopmentPlan.md for each assignment documenting design decisions
- Generated console output analysis for A02 and A03
- Identified memory issues and proposed fixes in A02 and A03
- Created A05/A06 review summaries for Python and Java polymorphism

### 2. What I Directed / Piloted

#### A01 — Company
- Fixed `Company::operator=` from empty body to proper deep copy via `clone()`
- Fixed `Company::bestPaidEmployees()` to collect ALL max-salary employees into a vector instead of single pointer
- Fixed `Company::displaySalaries()` to show only total payroll (not per-employee detail)
- Added `Company::inputEmployees()` for interactive input
- Added missing `Company()` default constructor
- Added Company test section to Main.cpp

#### A02 — Console Output Analysis
- Reviewed and corrected comment labels (`da2`/`da3` → `db1`/`db2`)
- Added DerivedA copy constructor output line (chains to Base default)
- Added slicing notes for `f(da1)`/`f(db1)` when passed by value
- Added notes on memory leaks when `pb` is reassigned without `delete`
- Added UB note for `delete pb` with non-virtual destructor

#### A03 — Console, Memory Issues, I/O Operators
- Kept Q1 (console output) and Q2 (memory issues) in Output.md as the report deliverable
- Provided separate 3.h/3.cpp with corrected I/O operators for Q3
- Fixed `foo` signature from `foo(A* a, const A& b)` to `foo(A a, const A& b)` to produce correct slicing behavior matching the original analysis
- Added `operator<<` and `operator>>` for both class A and B

#### A04 — Prince and Princess
- Fixed `Merchant` constructor to take `(float unitPrice, int qty)` parameter
- Fixed `Merchant::deduct()` to check `money >= cost` before spending (no negative money)
- Fixed `Sage::deduct()` to return `IQ >= req` without modifying IQ
- Fixed `Warrior::deduct()` to check strength before subtracting debuff
- Fixed `Castle::currentGatekeeper` initialization from `gatekeepers.size()` to `0`
- Added forward declaration of `Gatekeeper` in Castle.h for `vector<Gatekeeper*>`
- Fixed duplicate `Castle` destructor (inline `{}` in header conflicted with cleanup body in .cpp)

#### A05 — Python Polymorphism
- Verified review notes cover duck typing, method overriding, operator overloading, ABCs, singledispatch, mixins, callables

#### A06 — Java Polymorphism
- Verified review notes cover overloading vs overriding, abstract classes, interfaces, covariant returns, instanceof

### 3. What I Did Myself
- Analyzed assignment specifications and determined the inheritance/polymorphism structure for each task
- Made all design decisions: abstract vs concrete classes, constructor signatures, guard conditions, salary formulas
- Reviewed every line of generated/fixed code for correctness against specs
- Caught inconsistencies and directed fixes (e.g., `displaySalaries` total-only, `Sage` no IQ modification, `Merchant` quantity parameter)
- Verified all C++ assignments compile and run correctly

---

## Key Design Decisions (All Mine)

| # | Decision | Rationale |
|---|----------|-----------|
| 1 | `Employee` is abstract with pure virtual `getSalary()` | No meaningful salary for a generic employee; forces derived classes to implement |
| 2 | 5 constructors per class including string-format parser | Matches assignment requirement and provides flexible construction |
| 3 | Simplified `Date` class (not W3's full version) | Avoids unnecessary dependencies; only needs store+display for hire dates |
| 4 | `Company::displaySalaries()` shows total payroll only | Matches prof. spec (aggregate, not per-employee) |
| 5 | `Company::bestPaidEmployees()` uses vector for all max-salary employees | Correctly handles ties instead of returning a single winner |
| 6 | Polymorphic deep copy via `clone()` virtual method | Prevents slicing when copying through base pointer |
| 7 | `Sage::deduct()` does not modify IQ | Spec: answering a question does not reduce prince's IQ |
| 8 | `Warrior::deduct()` subtracts debuff after passing the check | Spec: strength reduced slightly after victory |
| 9 | `Castle::successOrNot()` works on a local copy of Prince | Original prince stats remain unchanged regardless of outcome |

---

## Academic Integrity
- AI generated initial code and analysis, but I directed the structure and design of every class
- All bug fixes and spec-violation corrections were piloted by me
- Every constructor, method, inheritance relationship, and deduction rule is verified and understood by me
- I can explain and modify any part of the code independently

---

## Files Submitted

### A01 — Company Employee Management
| File | Description |
|------|-------------|
| `Date.h/.cpp` | Simplified Date class (minimal, self-contained) |
| `Employee.h/.cpp` | Abstract base class with 5 constructors, virtual methods, pure virtual `getSalary()` |
| `OfficeEmployee.h/.cpp` | Derived class: salary = workingDays × 300,000 VND |
| `Worker.h/.cpp` | Derived class: salary = producedItems × 5,000 VND |
| `Company.h/.cpp` | Aggregation class with deep copy, total payroll, best-paid employees |
| `Main.cpp` | Tests all constructors + polymorphism + company operations |
| `classDiagram.mmd` | Mermaid class diagram |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A02 — Console Output Analysis
| File | Description |
|------|-------------|
| `Output.md` | Step-by-step execution trace with constructor/destructor call order, slicing notes, UB notes |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A03 — Console, Memory Issues, I/O Operators
| File | Description |
|------|-------------|
| `Output.md` | Q1 console output analysis + Q2 memory issue identification and fixes |
| `3.h` | Header with class A/B declarations + I/O operator friends |
| `3.cpp` | Full corrected implementation with deep copy, virtual dtor, Rule of Three, I/O operators |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A04 — Prince and Princess
| File | Description |
|------|-------------|
| `Castle.h` | Prince struct, Gatekeeper abstract base, Castle aggregation with gate sequence |
| `Castle.cpp` | Castle destructor (cleanup), Prince::display, successOrNot simulation |
| `Gatekeeper.h` | Merchant, Sage, Warrior derived classes |
| `Gatekeeper.cpp` | Deduction logic for all three gate types |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A05 — Python Polymorphism
| File | Description |
|------|-------------|
| `OOP_Python_Polymorphism.md` | Slide presentation |
| `OOP_Python_Polymorphism.pdf` | Rendered PDF |
| `Review.txt` | Concise review of key concepts |

### A06 — Java Polymorphism
| File | Description |
|------|-------------|
| `OOP_Java_Polymorphism.md` | Slide presentation |
| `OOP_Java_Polymorphism.pdf` | Rendered PDF |
| `Review.txt` | Concise review of key concepts |

---

## Conclusion

This proposal documents responsible AI use for W5 across all six assignments. AI was used as a code generator, analysis assistant, and document author under my direction. I provided the requirements, reviewed all output, piloted specific fixes for spec violations and bugs, and validated every inheritance relationship, constructor overload, virtual dispatch, and deduction rule. All design decisions — inheritance hierarchy, analysis accuracy, constructor patterns, guard logic — were made by me, not the AI.
