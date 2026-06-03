# Assignment 2 - Development Plan
## Point and Triangle Classes Implementation

### 0. Prompting Plan

#### Initial Prompt
```
Create Point and Triangle classes in C++ with the following requirements:

Point class:
- Attributes: x, y coordinates
- Methods: input, output, distance between two points, distance to Ox axis, distance to Oy axis

Triangle class:
- Attributes: three Point objects (A, B, C)
- Methods: input, output, isValidTriangle, determine type, calculate perimeter, 
  calculate area, find center G (centroid)
- Create a main() function with an interactive menu to demonstrate all methods
- Design class diagrams using Mermaid format
```

#### Follow-up Prompts
1. "Create Point class with coordinate attributes and distance methods"
2. "Create Triangle class that uses three Point objects"
3. "Implement triangle validation using triangle inequality theorem"
4. "Implement triangle type detection (equilateral, isosceles, right, scalene)"
5. "Implement perimeter, area (using cross product), and centroid calculations"
6. "Create Main.cpp with interactive menu for testing both classes"
7. "Generate Mermaid class diagram showing Point and Triangle relationship"
8. "Review code for bugs and mathematical accuracy"

#### Refinement Prompts
- "Create a Vector helper struct for geometric calculations"
- "Use cross product method for area calculation"
- "Ensure triangle validation in constructor"
- "Add floating-point comparison tolerance for right angle detection"
- "Create menu with options for Point operations and Triangle operations separately"

### 1. Requirements Analysis
- Implement Point class with x, y coordinates
- Implement Triangle class using 3 Point objects
- Calculate distances, triangle properties (validity, type, perimeter, area, centroid)
- Create interactive menu for user demonstration

### 2. Design Phase
- **Point Class**: Represents 2D coordinate with distance calculations
- **Triangle Class**: Represents triangle using 3 points with geometric calculations
- **Class Diagram**: Design using Mermaid format showing both classes and their relationship
- **Helper Classes**: Vector struct for geometric calculations (not required but useful)

### 3. Implementation Steps

#### Step 1: Create Point Class
**Coordinator.h / Point.cpp**
- Attributes: x, y (double for precision)
- Constructors: default, parameterized, copy
- Methods:
  - input(): read x, y from user
  - display(): output as (x, y)
  - distance(Point b): Euclidean distance between two points
  - disToOx(): absolute value of y-coordinate
  - disToOy(): absolute value of x-coordinate

#### Step 2: Create Triangle Class
**Triangle.h / Triangle.cpp**
- Attributes: Point A, B, C (three vertices)
- Constructors: default, parameterized with validation
- Methods:
  - input(): read three points
  - display(): output all vertices
  - isValid(): check triangle inequality theorem
  - type(): determine triangle type (equilateral, isosceles, right, scalene)
  - outputType(): display triangle type as string
  - perimeter(): sum of three side lengths
  - area(): using cross product formula
  - centerG(): calculate centroid (geometric center)

#### Step 3: Implement Point Methods
- distance(): √[(x₂-x₁)² + (y₂-y₁)²]
- disToOx(): |y|
- disToOy(): |x|
- Additional helper: toVector() for Triangle calculations

#### Step 4: Implement Triangle Validation
- isValid(): Check a + b > c, b + c > a, a + c > b
- Prevents degenerate triangles (collinear points)

#### Step 5: Implement Triangle Type Detection
- Equilateral: all three sides equal
- Isosceles: two sides equal
- Right: Pythagorean theorem (a² + b² = c²)
- Isosceles Right: combination of above
- Scalene: all sides different

#### Step 6: Implement Triangle Calculations
- perimeter(): AB + BC + CA
- area(): |AB × AC| / 2 (cross product method)
- centerG(): ((x₁+x₂+x₃)/3, (y₁+y₂+y₃)/3)

#### Step 7: Create Helper Vector Struct
- Support cross product and dot product operations
- Simplify area calculation
- Helper for centroid calculation

#### Step 8: Create Main Function with Menu
- Display menu options for Point and Triangle operations
- Allow user to input points and create triangles
- Demonstrate all required functionality
- Loop until user exits

#### Step 9: Testing
- Test point distances and axis distances
- Test triangle validity with various point configurations
- Test all triangle types detection
- Test perimeter, area, centroid calculations
- Test edge cases: collinear points, zero-area triangles

### 4. Testing Plan
| Test Case | Input | Expected Output | Status |
|-----------|-------|----------------|--------|
| Point distance | A(0,0), B(3,4) | 5.0 | ✓ |
| Distance to Ox | A(3,4) | 4.0 | ✓ |
| Distance to Oy | A(3,4) | 3.0 | ✓ |
| Valid triangle | (0,0), (3,4), (6,0) | true | ✓ |
| Invalid triangle | (0,0), (1,1), (2,2) | false | Need test |
| Equilateral | (0,0), (1,0), (0.5,√3/2) | Equilateral | Need test |
| Isosceles | (0,0), (2,0), (1,2) | Isosceles | Need test |
| Right triangle | (0,0), (3,0), (0,4) | Right | Need test |
| Scalene | (0,0), (3,4), (6,0) | Scalene | ✓ |
| Perimeter | (0,0), (3,0), (0,4) | 12.0 | ✓ |
| Area | (0,0), (3,0), (0,4) | 6.0 | ✓ |
| Centroid | (0,0), (3,0), (0,3) | (1,1) | ✓ |

### 5. Deliverables
- [x] Coordinator.h - Point and Vector declarations
- [x] Point.cpp - Point implementation
- [x] Vector.cpp - Vector helper implementation
- [x] Triangle.h - Triangle class declaration
- [x] Triangle.cpp - Triangle implementation
- [x] Main.cpp - Main function with interactive menu
- [x] ClassDiagram.md - Mermaid class diagram
- [x] centerG() calculation fixed (3.0 instead of 6.0)

### 6. Known Issues
- type() right angle detection uses basic floating-point comparison (works but could use epsilon tolerance for better precision)
- Vector struct could be refactored into separate files for better organization

### 7. Geometric Formulas Used
- **Distance**: d = √[(x₂-x₁)² + (y₂-y₁)²]
- **Triangle Inequality**: a + b > c (for all combinations)
- **Pythagorean Theorem**: a² + b² = c² (right angle detection)
- **Area (Cross Product)**: A = |AB × AC| / 2
- **Centroid**: G = ((x₁+x₂+x₃)/3, (y₁+y₂+y₃)/3)

### 8. Future Improvements
- Add circumcenter and incenter calculations
- Add angle calculations
- Add point-in-triangle testing
- Add triangle-triangle intersection
- Better floating-point comparison (epsilon tolerance)
- Separate Vector into its own proper class file
