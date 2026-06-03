# Assignment 1 - Development Plan
## Fraction Class Implementation

### 0. Prompting Plan

#### Initial Prompt
```
Create a Fraction class in C++ with the following requirements:
- Attributes: numerator, denominator
- Methods: input, output, add, subtract, multiply, divide (with zero division handling), 
  reduce, compare, isPositive, isNegative, isZero
- Create a main() function with an interactive menu to demonstrate all methods
- Design a class diagram using Mermaid format
```

#### Follow-up Prompts
1. "Create the Fraction.h header file with class declaration"
2. "Implement all methods in Fraction.cpp"
3. "Create Main.cpp with interactive menu for testing"
4. "Generate Mermaid class diagram"
5. "Review code for bugs and edge cases"
6. "Fix the reduce() method to use proper GCD algorithm"
7. "Add exception handling for division by zero"

#### Refinement Prompts
- "Make revert() a private helper method"
- "Ensure denominator is always positive"
- "Add input validation for zero denominator"
- "Create a menu with numbered options for each operation"

### 1. Requirements Analysis
- Implement a Fraction class with numerator and denominator
- Support basic arithmetic operations (add, subtract, multiply, divide)
- Handle edge cases (division by zero, fraction reduction)
- Provide comparison and sign checking methods
- Create interactive menu for user demonstration

### 2. Design Phase
- **Class Design**: Create Fraction class with private attributes (num, denom)
- **Class Diagram**: Design using Mermaid format showing attributes and methods
- **Method Planning**:
  - Constructors: default, parameterized, copy
  - Input/Output: user interaction methods
  - Arithmetic: add, subtract, multiply, divide
  - Utilities: reduce, compare, isPositive, isNegative, isZero
  - Helper: revert (private method for sign normalization)

### 3. Implementation Steps

#### Step 1: Create Class Structure
- Define Fraction.h header file with class declaration
- Declare private attributes: num, denom
- Declare public methods as per requirements

#### Step 2: Implement Constructors
- Default constructor: initialize to 0/1
- Parameterized constructor: validate denominator ≠ 0
- Copy constructor and assignment operator

#### Step 3: Implement Basic I/O
- input(): read numerator and denominator from user
- display(): output fraction in "num/denom" format

#### Step 4: Implement Arithmetic Operations
- add(): (a/b) + (c/d) = (ad + bc) / (bd)
- subtract(): (a/b) - (c/d) = (ad - bc) / (bd)
- multiply(): (a/b) × (c/d) = (ac) / (bd)
- divide(): (a/b) ÷ (c/d) = (ad) / (bc), throw exception if c = 0

#### Step 5: Implement Utility Methods
- reduce(): simplify fraction using GCD (Euclidean algorithm)
- revert(): normalize sign (negative to numerator, denominator always positive)
- compare(): compare two fractions
- isPositive(), isNegative(), isZero(): check fraction sign

#### Step 6: Create Main Function with Menu
- Display menu options
- Handle user input for operation selection
- Demonstrate each method functionality
- Loop until user exits

#### Step 7: Testing
- Test all arithmetic operations
- Test edge cases: division by zero, zero numerator
- Test fraction reduction: 2/4 → 1/2, 6/9 → 2/3
- Test negative fractions: -1/2, 1/-2 → -1/2
- Test comparison and sign checking

### 4. Testing Plan
| Test Case | Input | Expected Output | Status |
|-----------|-------|----------------|--------|
| Add fractions | 1/2 + 3/4 | 5/4 | ✓ |
| Subtract fractions | 3/4 - 1/2 | 1/4 | ✓ |
| Multiply fractions | 1/2 × 3/4 | 3/8 | ✓ |
| Divide fractions | 1/2 ÷ 3/4 | 2/3 | ✓ |
| Divide by zero | 1/2 ÷ 0/1 | Exception thrown | ✓ |
| Reduce fraction | 2/4 | 1/2 | ✓ |
| Negative fraction | 1/-2 | -1/2 | ✓ |
| Compare fractions | 1/2 vs 3/4 | 1/2 < 3/4 | ✓ |
| Check positive | 1/2 | true | ✓ |
| Check negative | -1/2 | true | ✓ |
| Check zero | 0/1 | true | ✓ |

### 5. Deliverables
- [x] Fraction.h - Header file with class declaration
- [x] Fraction.cpp - Implementation file
- [x] Main.cpp - Main function with demonstration
- [x] ClassDiagram.md - Mermaid class diagram
- [ ] Interactive menu (TODO)
- [ ] Fix reduce() GCD algorithm (TODO)

### 6. Known Issues
- Main.cpp lacks interactive menu (currently hardcoded tests)
- compare() method naming ambiguous (should clarify >= behavior)

### 7. Prompts for Remaining Tasks
```
"Add an interactive menu to Main.cpp with options:
 1. Input two fractions
 2. Add fractions
 3. Subtract fractions
 4. Multiply fractions
 5. Divide fractions
 6. Compare fractions
 7. Check if positive/negative/zero
 8. Exit"
"Test all edge cases and ensure proper error handling"
```

### 8. Future Improvements
- Add operator overloading (+, -, *, /, ==, <, >, etc.)
- Add stream operators (<<, >>) for easier I/O
- Add support for mixed numbers (e.g., 1 1/2)
- Add more robust input validation
