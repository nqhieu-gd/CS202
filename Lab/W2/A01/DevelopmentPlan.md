# Assignment 1 - Development Plan
## Point2D Class Implementation with Constructors/Destructors

### 1. Requirements Analysis
- Implement Point2D class with 5 different constructors
- Each constructor must print identification message
- Add destructor that prints when called
- Implement toString() and clone()
- Demonstrate all features in main program

### 2. Constructor Design
1. **Default** - Point2D() → (0, 0)
2. **Single int** - Point2D(int x) → (x, 0)
3. **Two ints** - Point2D(int x, int y) → (x, y)
4. **Copy** - Point2D(const Point2D&)
5. **String** - Point2D(string s) → parse "x,y"

### 3. Key Design Decisions
- Coordinates are `int` (integer precision, standalone class)
- Each constructor prints a unique cout message
- Destructor prints when object is destroyed
- getX()/getY() exposed for Triangle composition in A02

### 4. Testing Plan
| Test Case | Input | Expected Output |
|-----------|-------|----------------|
| Default | Point2D p1 | "Point2D::Default constructor" |
| Single param | Point2D p2(5) | "Point2D::Constructor(int x)", (5,0) |
| Two params | Point2D p3(15,-2) | "Point2D::Constructor(int x, int y)", (15,-2) |
| Copy | Point2D p4(p3) | "Point2D::Copy constructor" |
| String | Point2D p5("10,20") | "Point2D::Constructor(string s)", (10,20) |
| toString | p3.toString() | "15,-2" |
| clone | p6 = p3.clone() | New object with (15,-2) |
| Destructor | Program ends | "Point2D::Destructor" for each |

### 5. Deliverables
- [x] Point2D.h - Header file with class declaration
- [x] Point2D.cpp - Implementation with 5 constructors
- [x] Main.cpp - Demonstration program

### 6. Constructor/Destructor Output
```
Point2D::Default constructor
Point2D::Constructor(int x)
Point2D::Constructor(int x, int y)
Point2D::Copy constructor
Point2D::Constructor(string s)
Point2D::Constructor(int x, int y)  // from clone()
...
Point2D::Destructor  // for each object
```
