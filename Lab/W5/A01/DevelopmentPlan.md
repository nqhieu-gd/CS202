# A01 — Company Employee Management — Development Plan

## Requirements Analysis

Build an employee management system using inheritance + Company aggregation:

| Class | Base? | Attributes | Salary Formula |
|-------|-------|------------|----------------|
| Employee | Base | empId, fullName, hireDate (Date), address | Abstract / pure virtual |
| OfficeEmployee | extends Employee | (inherits) + workingDays | workingDays * 300,000 VND/day |
| Worker | extends Employee | (inherits) + producedItems | producedItems * 5,000 VND/item |
| Company | (standalone) | Employee* array, employeeCount | Total / max salary methods |

Required methods per employee class:
- Input employee info
- Print employee info to console
- Compute monthly salary (pure virtual in base, override in derived)
- At least 5 constructors per class

Company methods:
- Input a list of employees
- Print info of all employees
- Print total salary the company must pay
- Print employees with highest salary

### 5 Constructors

| # | Signature | Note |
|---|-----------|------|
| 1 | `Employee()` | Default — empty values |
| 2 | `Employee(id, name, date, address)` | Full parameterized |
| 3 | `Employee(const Employee&)` | Copy constructor |
| 4 | `Employee(id, date)` | Partial — name and address defaulted |
| 5 | `Employee(const string& data)` | Parse fixed-format string: `"_id_ || _name_ || _hiredate_ || _address_"` |

Derived classes mirror with their own extra fields.

## Design Decisions

### Inheritance Structure
- `Employee` is an abstract base (pure virtual `getSalary()`)
- `OfficeEmployee` and `Worker` are concrete derived classes
- Virtual destructor in `Employee` for safe polymorphic deletion

### Company Class
- Stores `Employee*` in a fixed-size array (or dynamic pointer array)
- Input: reads count N, then N employees (prompt for type: 1=Office, 2=Worker)
- Display: iterate polymorphically, call `displayInfo()` + `getSalary()`
- Total salary: sum of `getSalary()` across all employees
- Max salary: track highest, collect all matching employees

### Simplified Date Class
- Lightweight `Date.h` within the A01 folder
- Minimal members: day, month, year (int), constructor, display, basic validation

### String Format Constructor (#5)
- Parse delimiter ` || ` (space-pipe-pipe-space)
- Extract: empId, fullName, hireDate, address

### Constructor Chaining
- Derived constructors call matching base constructor via initializer list

### Salary Computation
- `Employee::getSalary()` is pure virtual
- `OfficeEmployee::getSalary()` = workingDays * 300000
- `Worker::getSalary()` = producedItems * 5000

### Class Diagram (Mermaid)
- Use `<<abstract>>`, `<<concrete>>`, `<<constructor>>`, `<<virtual>>`, `<<override>>`, `<<pure virtual>>` stereotypes

## Polymorphism Aspect

The Company class uses polymorphism to treat all employees uniformly:
- `Employee*` array holds both OfficeEmployee and Worker objects
- `getSalary()` dispatches to the correct derived implementation at runtime
- `displayInfo()` and `inputInfo()` use virtual dispatch

## Potential Problems & Resolutions

| Problem | Resolution |
|---------|------------|
| How to handle unknown employee type when inputting | Prompt user for type code (1=Office, 2=Worker) before reading data |
| Memory management for Employee* array | Use `delete[]` or vector of smart pointers |
| Date string format varies | Document expected format; parse flexibly |
| 5 constructors × 3 classes = 15 total | Use constructor delegation to avoid code duplication |
| Deep copy of address strings | Use `std::string` — copy handled automatically |

## File Structure

```
Lab/W5/A01/
├── Employee.h              — Base abstract class
├── Employee.cpp            — Base implementation
├── OfficeEmployee.h        — Derived class header
├── OfficeEmployee.cpp      — Derived class implementation
├── Worker.h                — Derived class header
├── Worker.cpp              — Derived class implementation
├── Company.h               — Company aggregation class
├── Company.cpp             — Company implementation
├── Date.h                  — Simplified Date class
├── Main.cpp                — Test program
├── classDiagram.mmd        — Mermaid class diagram source
├── classDiagram.png        — Rendered diagram
└── DevelopmentPlan.md      — This file
```

## Testing

Compile:
```
g++ -std=c++11 Employee.cpp OfficeEmployee.cpp Worker.cpp Company.cpp Date.cpp Main.cpp -o Company.exe
```

Test scenarios:
1. Create employees via each of 5 constructors
2. Compute salary for OfficeEmployee and Worker
3. Input and display via virtual functions
4. Company: input list, display all, compute total salary
5. Company: print employees with highest salary
6. Polymorphic array of Employee pointers
