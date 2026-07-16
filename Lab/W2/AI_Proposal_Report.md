# AI Proposal Report - CS202 Week 2 Assignments

## Student Information
- **Student**: Nguyen Quang Hieu - 25125043
- **Course**: CS202 - Programming Systems
- **Week**: Week 2

## W2 Assignment Overview

This proposal covers AI usage for Week 2 assignments:
- **A01**: Point2D Class — Constructors & Destructor (standalone)
- **A02**: Triangle Class — Composition with Point2D
- **A03**: MyIntArray Class — Dynamic Array with Constructors
- **A04**: Student Class — Dynamic C-Strings with Constructors
- **A05**: Theater Ticket System
- **A06**: Python OOP Presentation
- **A07**: Java OOP Presentation

Topic: **Constructors and Destructors** in C++ OOP

---

## AI Usage Declaration

### 1. What AI Did (Initial Implementation)
- Set up source files for A03–A07 based on w2.txt specifications
- Implemented initial versions of all constructors, methods, and Main.cpp demonstrations
- Created DevelopmentPlan.md files and presentation markdowns (A06, A07)

### 2. What I Directed / Piloted
- **A01**: Removed cross-week references to W1
- **A02**: Removed cross-week references to W1; added `float ratio` parameter to Triangle single-point constructor
- **A03**: Replaced `std::sort` with manual quicksort; added empty-array guards in `max()`/`min()`; changed string constructor to use `vector<int>` internally; added copy assignment operator
- **A04**: Changed 5th constructor from `Student(int id)` to `Student(int id, const char* name)`; added copy assignment operator; documented pipe-delimited string format
- **A05**: Reduced to 2 constructors (default + copy); moved price prompt into constructor; changed "filename" to "path to file"; added cancel option (0) during pricing prompt; split group purchase into consecutive + custom; removed standalone display chart from menu; chart shows automatically before purchase; refined statistics to match spec exactly; fixed Mermaid class diagram syntax and outdated members/methods
- **A05**: Removed `reset()` method (not needed)
- **A06/A07**: Removed cross-week references to W1

### 3. What I Did Myself
- Reviewed all code iteratively and identified needed changes
- Directed AI to apply specific fixes (quicksort, constructor signatures, UI flow)
- Made final call on all design decisions (which constructors to keep, menu structure, etc.)
- Validated every compile and verified output
- Understood and can explain all code submitted

---

## Academic Integrity
- AI was used as an implementation assistant under my direction
- Every change was reviewed, tested, and approved by me
- All design decisions and problem-solving were mine
- I can explain any part of the submitted code independently

---

## Files Submitted

### A01 — Point2D (Standalone, Verbose)
| File | Description |
|------|-------------|
| `Point2D.h/.cpp` | 5 constructors, destructor, `toString()`, `clone()` |
| `Main.cpp` | Full constructor/destructor demonstration |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A02 — Triangle (Composition with Silent Point2D, Zoom Ratio)
| File | Description |
|------|-------------|
| `Point2D.h/.cpp` | Silent component class (float coordinates) |
| `Triangle.h/.cpp` | 5 constructors + ratio parameter, geometric methods |
| `Main.cpp` | Tests all constructors, area, centroid, type classification |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A03 — MyIntArray (Dynamic Array)
| File | Description |
|------|-------------|
| `MyIntArray.h/.cpp` | 5 constructors, copy assignment, manual quicksort |
| `Main.cpp` | Tests all constructors, sorting, edge cases |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A04 — Student (Dynamic C-Strings)
| File | Description |
|------|-------------|
| `Student.h/.cpp` | 5 constructors, `dup_str()`, copy assignment, pipe-delimited format |
| `Main.cpp` | Tests all constructors, clone, string parsing |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A05 — Theater Ticket System
| File | Description |
|------|-------------|
| `ClassDiagram.md` | Mermaid class diagram |
| `Theater.h/.cpp` | 2 constructors, cancel option, consecutive/custom group purchase, file loading |
| `Main.cpp` | Program entry point |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A06 — Python OOP Presentation
| File | Description |
|------|-------------|
| `OOP_Python_Presentation.md` | 31-slide Python constructor/destructor presentation |
| `DevelopmentPlan.md` | Design and prompting documentation |

### A07 — Java OOP Presentation
| File | Description |
|------|-------------|
| `OOP_Java_Presentation.md` | 31-slide Java constructor/destructor presentation |
| `DevelopmentPlan.md` | Design and prompting documentation |

---

## Conclusion

This proposal documents responsible AI use for W2. AI handled initial code generation under my direction; all refinements, bug fixes, and design decisions were piloted by me. Every line of code is reviewed, understood, and verified.
