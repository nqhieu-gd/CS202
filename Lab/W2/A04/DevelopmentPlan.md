# Assignment 4 - Development Plan
## Student Class Implementation with Constructors/Destructors

### 1. Requirements Analysis
- Implement Student class with id, fullname, address, gpa
- fullname and address are char* (dynamic C-strings)
- 5 different constructors each printing identification message
- Destructor printing when called (must delete char* arrays)
- toString() and clone() for independent deep copy

### 2. Constructor Design
1. **Default** - Student() → id=0, name="", address="", gpa=0.0
2. **ID + name** - Student(int id, const char* name) → partial enrollment data
3. **Full** - Student(int id, const char* name, const char* addr, double gpa)
4. **Copy** - Student(const Student&) → deep copy of C-strings
5. **String** - Student(string s) → parse "id|fullname|address|gpa"

### 3. Key Design Decisions
- char* requires manual deep copy with dup_str() helper
- Rule of Three: destructor + copy constructor + copy assignment operator
- String format uses pipe (|) delimiter (names/addresses may contain commas)
- Format: "id|fullname|address|gpa" — e.g. "103|Le Van C|789 Pasteur, Q3, HCMC|3.50"
- Missing fields default to empty/zero
- ID + name constructor covers real scenario: enrolling students with partial data

### 4. Testing Plan
| Test Case | Input | Expected Output |
|-----------|-------|----------------|
| Default | Student() | id=0, name="", address="", gpa=0 |
| ID + name | Student(201, "Nguyen Van D") | id=201, name="Nguyen Van D" |
| Full | Student(101, "NV A", "...", 3.75) | All fields set |
| Copy | s4(s2) | Same data as s2 |
| String | s5("103\|...\|3.50") | Parsed from pipe-delimited string |

### 5. Deliverables
- [x] Student.h - Header with class declaration
- [x] Student.cpp - Implementation with 5 constructors + operator=
- [x] Main.cpp - Demonstration program

### 6. String Format Reference
```
Format:  id|fullname|address|gpa
Example: 103|Le Van C|789 Pasteur, Q3, HCMC|3.50
```
Pipe (|) is the delimiter because names and addresses may contain commas.
