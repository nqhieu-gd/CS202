# AI Proposal Report - CS202 Week 2 Assignments

## Student Information
- **Student**: Nguyen Quang Hieu - 25125043
- **Course**: CS202 - Programming Systems
- **Week**: Week 2

## W2 Assignment Overview

This proposal covers AI usage for Week 2 assignments:
- **A01**: Point2D Class — Constructors & Destructor (standalone)
- **A02**: Triangle Class — Composition with Point2D

Topic: **Constructors and Destructors** in C++ OOP

---

## AI Usage Declaration

### 1. Purpose of AI Assistance for W2 Tasks

W2 focuses on object lifecycle management. AI tools helped with:
- **Constructor overloading** — Syntax for multiple constructors with different signatures
- **Initializer lists** — Efficient member initialization using `: member(value)` syntax
- **String parsing** — Using `string::find()` and `stoi()` to parse "x,y" format
- **Composition design** — How a Triangle containing 3 Point2D objects manages construction order
- **Destructor behavior** — Understanding when destructors fire and in what order

### 2. Scope of AI Usage for W2 Assignments

#### What AI Helped With:
- Constructor syntax and initializer list patterns
- String-to-int parsing logic (`find`, `substr`, `stoi`)
- Deciding when component classes (Point2D in A02) should be "silent"
- Cross product formula for triangle area
- Formatting `toString()` output with `stringstream`

#### What I Did Myself:
- Understanding all assignment requirements
- Designing the class interfaces (what methods are needed and why)
- Deciding which constructors to implement and what each one should do
- Making the encapsulation choices (removing unnecessary setters)
- Writing the Main.cpp test programs
- Debugging compilation errors (e.g., `setX/setY` declared in .cpp but not .h)
- Verifying correctness of geometric calculations (area, perimeter, centroid)
- Making the design decision to use silent Point2D in A02 vs verbose in A01

---

### 3. Transparency Guidelines for W2

Each assignment includes `DevelopmentPlan.md` that documents:
- The prompts used with AI tools
- What AI contributed vs what I implemented
- Design decisions and trade-offs
- Testing approach and expected output

---

### 4. Academic Integrity for W2

#### My Approach:
- AI was used to understand syntax and patterns, not to blindly copy solutions
- Every line of code was read, understood, and tested
- Design decisions (constructor signatures, encapsulation, composition strategy) were made by me
- I can explain any part of the submitted code independently

#### Quality Standards:
- All code compiles without errors or warnings
- All constructors and destructor print identification messages as required
- `toString()` and `clone()` are implemented and tested
- Programs demonstrate all required features in Main.cpp

---

### 5. W2 Development Process

1. Read assignment spec — identified 5 required constructors + destructor + `toString()` + `clone()`
2. Reviewed W1 A02 Point/Triangle code as a starting base
3. Used AI to clarify constructor overloading and initializer list syntax
4. Implemented A01 (Point2D, verbose) — verified each constructor prints correctly
5. Designed A02 strategy: silent Point2D as a component inside Triangle
6. Implemented A02 (Triangle with 5 constructors) — verified Triangle messages only
7. Debugged A02 compile error: `setX/setY` in .cpp had no matching declaration in .h — removed orphaned setters
8. Wrote Main.cpp for both assignments with full coverage of all constructors
9. Documented process in DevelopmentPlan.md files

---

### 6. Key Design Decisions Made

#### A01 — Verbose Point2D
Every constructor and the destructor print a message. This makes the object
lifecycle visible when testing the class standalone.

#### A02 — Silent Point2D as Component
When Triangle is composed of 3 Point2D objects, verbose Point2D constructors
would flood the output (3 silent + 1 Triangle message per construction). The
decision to silence Point2D in A02 keeps the output focused on Triangle's
lifecycle — the subject being demonstrated.

#### Constructor for One Point (Triangle)
`Triangle(const Point2D& A)` creates a unit right triangle anchored at A, with
B at `(A.x + 1, A.y)` and C at `(A.x, A.y + 1)`. This provides a meaningful
default shape rather than a degenerate triangle.

#### String Parsing Format
- Point2D: `"x,y"` — single comma delimiter
- Triangle: `"x1,y1;x2,y2;x3,y3"` — semicolons separate points, commas separate coordinates within each point. This avoids ambiguity when nesting Point2D parsing inside Triangle parsing.

#### Encapsulation
Setters (`setX`, `setY`) were removed from Triangle's Point2D component.
Getters `getX()` and `getY()` are kept only because Triangle's area and
centroid calculations need them internally.

---

### 7. W2 Learning Outcomes

#### What I Learned:
- Constructor overloading — multiple constructors with different parameter types
- Initializer lists — cleaner and more efficient than assigning in the body
- Destructor execution order — members destroyed in reverse declaration order
- Object composition — a Triangle owning 3 Point2D objects, not inheriting from them
- Verbose vs silent design — choosing what to print based on class role

#### How I Prove Understanding:
- Can explain the order constructors and destructors fire in both A01 and A02
- Can describe why A02's Point2D is silent while A01's is verbose
- Can trace through the string parsing logic step by step
- Wrote test cases that exercise every constructor path

---

### 8. W2 Compliance Summary

- ✓ All AI usage documented in DevelopmentPlan.md files
- ✓ All code compiles and runs correctly
- ✓ All 5 constructors implemented per assignment spec
- ✓ Destructor implemented with cout statement
- ✓ `toString()` implemented in both classes
- ✓ `clone()` implemented in both classes
- ✓ Understand and can explain every line submitted
- ✓ Followed academic integrity rules

---

## Conclusion

This proposal demonstrates responsible AI use for W2 assignments. AI provided
guidance on C++ syntax (initializer lists, string parsing, stringstream), while
I made all design decisions, implemented the programs, debugged errors, and
verified correctness. The core learning objectives — understanding constructors,
destructors, and object lifecycle — were achieved through hands-on implementation
and testing, not just AI-generated output.

---

## Appendix A: AI Tools Used in W2

**Amazon Q Developer / Kiro** — Primary tool for:
- Constructor and initializer list syntax
- Debugging the `setX/setY` declaration mismatch in A02
- `stringstream` usage for `toString()`

**ChatGPT / Claude** — Supporting tool for:
- Clarifying constructor overloading rules
- Explaining composition vs inheritance trade-offs
- Cross product area formula reference

---

## Appendix B: Files Submitted

### A01 — Point2D (Standalone, Verbose)
| File | Description |
|------|-------------|
| `Point2D.h` | Class declaration with 5 constructors |
| `Point2D.cpp` | Implementation — all constructors print messages |
| `Main.cpp` | Tests all 5 constructors, `toString()`, `clone()`, distance |
| `DevelopmentPlan.md` | Full design and prompting documentation |

### A02 — Triangle (Composition with Silent Point2D)
| File | Description |
|------|-------------|
| `Point2D.h` | Silent component class declaration |
| `Point2D.cpp` | Silent implementation (no cout in constructors/destructor) |
| `Triangle.h` | Triangle class with 5 constructors |
| `Triangle.cpp` | Implementation — Triangle constructors print, Point2D silent |
| `Main.cpp` | Tests all 5 Triangle constructors, geometric methods, `clone()` |
| `DevelopmentPlan.md` | Full design and prompting documentation |

---

## Appendix C: Constructor/Destructor Output Summary

### A01 Expected Output (partial)
```
=== Testing Point2D Constructors ===

1. Creating p1 with default constructor:
Point2D::Default constructor
Point(0, 0)
toString: 0,0

...

=== Program ending (destructors will be called) ===
Point2D::Destructor   (x6, once per object)
```

### A02 Expected Output (partial)
```
=== Testing Triangle Constructors ===

1. Creating t1 with default constructor:
Triangle::Default constructor
Triangle: A(0, 0) B(1, 0) C(0, 1)

...

=== Program ending (destructors will be called) ===
Triangle::Destructor   (once per Triangle object)
```

Note: Point2D destructors fire silently inside each Triangle destructor — they
run but produce no output, keeping the lifecycle trace clean and focused on
Triangle objects.
