# AI Proposal Report - CS202 Week 4 Assignments

## Student Information
- **Student**: Nguyen Quang Hieu - 25125043
- **Course**: CS202 - Programming Systems
- **Week**: Week 4

## W4 Assignment Overview

This proposal covers AI usage for Week 4 assignments:
- **A01**: Company Employee Management — Inheritance
- **A02**: Bank Account — Inheritance with Savings Account
- **A03**: Shopping Cart Simulation — Inheritance with Product Types
- **A04**: Python Inheritance Presentation
- **A05**: Java Inheritance Presentation

Topic: **Inheritance** in C++ OOP

---

## AI Usage Declaration

**Declaration B: I did use AI for this homework.**

### 1. What AI Did (Under My Direction)
- Generated initial header and source files for A01 (Employee, OfficeEmployee, Worker), A02 (BankAccount, SavingBankAccount), A03 (CartItem, MainProduct, FreeGift, Shop, ShoppingCart)
- Created DevelopmentPlan.md for each assignment documenting design decisions
- Generated Mermaid class diagrams for all three assignments
- Created presentation slides for A04 (Python Inheritance) and A05 (Java Inheritance)

### 2. What I Directed / Piloted

#### A01 — Company
- Clarified that Date should be a simplified self-contained class (not reused from W3)
- Specified the 5-constructor pattern: default, full, copy, partial (id+date), string-format parser
- Defined the string format: `"_id_ || _name_ || _date_ || _address_"` (and extended for derived classes)
- Directed abstract base with pure virtual `getSalary()`, virtual `inputInfo()`/`displayInfo()`

#### A02 — Bank Account
- Specified simple interest formula: `balance * rate * (savingMonths / 12.0)`
- Directed that `checkBalance()` returns `balance + interest` but does **not** modify the stored `balance` field
- Directed `withdrawImmediately()` to set a `freePeriod` flag and drop rate to 2%
- Defined deposit/withdraw guards when `savingMonths < period`
- Specified the 5-constructor pattern for both classes

#### A03 — Shopping Cart
- Provided the reference image describing the shopping cart layout (products, variants, quantities, unit prices, free gifts, shop groupings, total calculation)
- Directed inheritance hierarchy: CartItem → MainProduct (with originalPrice) and FreeGift (unitPrice always 0)
- Defined Shop grouping with check/uncheck logic
- Specified quantity adjustment with clamp at 1
- Directed console simulation focused on products, quantities, unit prices, and total price only

#### A04 — Python Inheritance Presentation
- Specified the three required topics: inheritance syntax, method overriding, constructor call order
- Reviewed and reorganized slide sequence for clarity
- Verified technical accuracy of Python MRO and ABC concepts

#### A05 — Java Inheritance Presentation
- Same three topics as A04 but adapted for Java's single-inheritance model
- Verified `super()` chaining, `@Override`, covariant return types, and interface default method resolution

### 3. What I Did Myself
- Analyzed the assignment specifications and determined the inheritance structure for each assignment
- Made all design decisions: which classes are abstract vs concrete, constructor signatures, guard conditions, interest formula
- Reviewed every line of generated code for correctness
- Caught inconsistencies and directed fixes (e.g., simplified Date for A01, balance-unchanged semantics for A02)
- Verified all three C++ assignments compile and run correctly

---

## Key Design Decisions (All Mine)

| # | Decision | Rationale |
|---|----------|-----------|
| 1 | `Employee` is abstract with pure virtual `getSalary()` | No meaningful salary for a generic employee; forces derived classes to implement |
| 2 | 5 constructors per class including string-format parser | Matches assignment requirement and provides flexible construction |
| 3 | Simplified `Date` class (not W3's full version) | Avoids unnecessary dependencies; only needs store+display for hire dates |
| 4 | `SavingBankAccount::checkBalance()` returns sum without modifying balance | Balance is the principal; interest is read-only computed on demand |
| 5 | `freePeriod` flag for immediate withdrawals | Preserves original rate field while allowing rate override |
| 6 | `CartItem` → `MainProduct` / `FreeGift` hierarchy | Clear inheritance: paid vs free items with different display behaviors |
| 7 | Shop owns CartItem pointers, ShoppingCart owns Shop pointers | Clear ownership hierarchy with RAII cleanup in destructors |
| 8 | Quantity clamp at 1 | Prevents invalid zero/negative quantities |

---

## Academic Integrity
- AI generated initial code, but I directed the structure and design of every class
- All bug fixes and refinements were piloted by me
- Every constructor, method, and inheritance relationship is verified and understood by me
- I can explain and modify any part of the code independently

---

## Files Submitted

### A01 — Company Employee Management
| File | Description |
|------|-------------|
| `Date.h` | Simplified Date class (minimal, self-contained) |
| `Employee.h/.cpp` | Abstract base class with 5 constructors, virtual methods |
| `OfficeEmployee.h/.cpp` | Derived class: salary = workingDays × 300,000 VND |
| `Worker.h/.cpp` | Derived class: salary = producedItems × 5,000 VND |
| `Main.cpp` | Tests all constructors + polymorphism |
| `classDiagram.mmd` | Mermaid class diagram |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A02 — Bank Account
| File | Description |
|------|-------------|
| `BankAccount.h/.cpp` | Base class with 5 constructors, deposit, withdraw, balance |
| `SavingBankAccount.h/.cpp` | Derived class with interest, period, free-period withdrawal |
| `Main.cpp` | Tests all constructors + guards + interest calculation |
| `classDiagram.mmd` | Mermaid class diagram |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A03 — Shopping Cart Simulation
| File | Description |
|------|-------------|
| `CartItem.h/.cpp` | Base class with name, variant, price, quantity, checked |
| `MainProduct.h/.cpp` | Derived with originalPrice for discount display |
| `FreeGift.h/.cpp` | Derived with unitPrice always 0 |
| `Shop.h/.cpp` | Groups items by merchant, with checked toggle |
| `ShoppingCart.h/.cpp` | Aggregates shops, computes total, checkout |
| `Main.cpp` | Simulates the reference cart scenario |
| `classDiagram.mmd` | Mermaid class diagram |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A04 — Python Inheritance Presentation
| File | Description |
|------|-------------|
| `OOP_Python_Inheritance.md` | 33-slide presentation |
| `Review.txt` | Concise review of key concepts |

### A05 — Java Inheritance Presentation
| File | Description |
|------|-------------|
| `OOP_Java_Inheritance.md` | 33-slide presentation |
| `Review.txt` | Concise review of key concepts |

---

## Conclusion

This proposal documents responsible AI use for W4 across all five assignments. AI was used as a code generator and slide author under my direction. I provided the requirements, reviewed all output, piloted specific fixes, and validated every inheritance relationship, constructor overload, and virtual method. All design decisions — inheritance hierarchy, constructor patterns, interest semantics, guard logic — were made by me, not the AI.
