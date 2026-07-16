# A01 — Company Employee Management — Development Plan

## Requirements Analysis

Build an employee management system using inheritance:

| Class | Base? | Attributes | Salary Formula |
|-------|-------|------------|----------------|
| Employee | Base | empId, fullName, hireDate (Date), address | Abstract / Not directly used |
| OfficeEmployee | extends Employee | (inherits) + workingDays | workingDays * 300,000 VND/day |
| Worker | extends Employee | (inherits) + producedItems | producedItems * 5,000 VND/item |

Required methods per class:
- Input employee info
- Print employee info to console
- Compute monthly salary (virtual in base, overridden in derived)
- At least 5 constructors per class

### 5 Constructors

| # | Signature | Note |
|---|-----------|------|
| 1 | `Employee()` | Default — empty values |
| 2 | `Employee(id, name, date, address)` | Full parameterized |
| 3 | `Employee(const Employee&)` | Copy constructor |
| 4 | `Employee(id, date)` | Partial — name and address defaulted |
| 5 | `Employee(const string& data)` | Parse fixed-format string: `"_id_ \|\| _name_ \|\| _hiredate_ \|\| _address_"` |

Derived classes mirror with their own extra fields.

## Design Decisions

### Inheritance Structure
- `Employee` is an abstract base (pure virtual `getSalary()`)
- `OfficeEmployee` and `Worker` are concrete derived classes
- Virtual destructor in `Employee` for safe polymorphic deletion

### Simplified Date Class
- Create a lightweight `Date.h` within the A01 folder (not reused from W3)
- Minimal members: day, month, year (int), constructor, display, basic validation
- Only needs to store and print hire date — no operator overloading required

### String Format Constructor (#5)
- Parse delimiter ` || ` (space-pipe-pipe-space)
- Extract: empId, fullName, hireDate (as "dd/mm/yyyy" or "yyyy-mm-dd"), address
- Throw or set error flag on malformed input

### Constructor Chaining
- Derived constructors call the matching base constructor via initializer list
- Employee(id, date) reuses Employee(id, "", date, "") as delegation (C++11)

### Salary Computation
- `Employee::getSalary()` is pure virtual → must override in derived
- `OfficeEmployee::getSalary()` = workingDays * 300000
- `Worker::getSalary()` = producedItems * 5000

### Input / Output
- `inputInfo()` reads from stdin with prompts
- `displayInfo()` prints formatted output
- Both are virtual — derived classes extend the base version (call base then add own fields)

### Class Diagram (Mermaid)
- Use `<<abstract>>`, `<<concrete>>`, `<<constructor>>`, `<<virtual>>`, `<<override>>`, `<<pure virtual>>` stereotypes
- Show inheritance arrows, attributes, and method signatures

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| How to handle string constructor parsing errors | Return a flag or use a static factory method with error status |
| Date string format varies | Document expected format; parse flexibly (try dd/mm/yyyy then yyyy-mm-dd) |
| Deep copy of addresses (dynamic string) | Use `std::string` — copy handled automatically |
| 5 constructors × 3 classes = 15 total | Use constructor delegation to avoid code duplication |
| OfficeEmployee/Worker must call Employee's correct constructor | Explicit base initializer in each derived constructor |

## File Structure

```
Lab/W4/A01/
├── Employee.h            — Base abstract class
├── Employee.cpp          — Base implementation
├── OfficeEmployee.h      — Derived class header
├── OfficeEmployee.cpp    — Derived class implementation
├── Worker.h              — Derived class header
├── Worker.cpp            — Derived class implementation
├── Date.h                — Simplified Date class (minimal, self-contained)
├── Main.cpp              — Test program
├── classDiagram.mmd      — Mermaid class diagram source
├── classDiagram.png      — Rendered diagram
└── DevelopmentPlan.md    — This file
```

## Testing

Compile:
```
g++ -std=c++11 Employee.cpp OfficeEmployee.cpp Worker.cpp Date.cpp Main.cpp -o Company.exe
```

Test scenarios:
1. Create Employee via each of 5 constructors (using derived classes)
2. Compute salary for OfficeEmployee and Worker
3. Input and display via virtual functions
4. Polymorphic array of Employee pointers
5. String constructor parsing
