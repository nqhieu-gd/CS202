# Assignment 2 - Development Plan
## Triangle Class Implementation with Constructors/Destructors

### 1. Requirements Analysis
- Implement Triangle class using composition (3 Point2D objects)
- 5 different constructors each printing identification message
- Destructor prints when called
- toString() and clone() methods
- Geometric calculations: isValid, getType, perimeter, area, centroid

### 2. Constructor Design
1. **Default** - Triangle() → (0,0), (1,0), (0,1)
2. **Point A + zoom ratio** - Triangle(Point2D A, float ratio = 1.0f) → B/C offset by ratio from A
3. **Three points** - Triangle(Point2D A, B, C) → full specification
4. **Copy** - Triangle(const Triangle&)
5. **String** - Triangle(string s) → parse "x1,y1;x2,y2;x3,y3"

### 3. Key Design Decisions
- Point2D uses `float` coordinates (non-integer zoom ratios, precise centroid)
- Point2D constructors are silent (no cout) to avoid output clutter from composition
- Only Triangle constructors print messages
- Zoom ratio parameter scales the default right triangle from point A
- String format "x1,y1;x2,y2;x3,y3" with semicolons separating points

### 4. Testing Plan
| Test Case | Input | Expected Output |
|-----------|-------|----------------|
| Default | Triangle t1 | (0,0), (1,0), (0,1), area=0.5 |
| Point A | Triangle(pA) | A at (2,3), B at (3,3), C at (2,4) |
| Point A + ratio 2 | Triangle(pA, 2.0f) | Zoomed: area=2 (4x default) |
| Three points | Triangle(p1,p2,p3) | Right triangle (0,0)-(3,0)-(0,4) |
| Copy | Triangle t4(t3) | Same as t3 |
| String | Triangle("1,1;4,1;2,4") | Scalene triangle |
| toString | t3.toString() | "0,0;3,0;0,4" |
| centroid | t3.centroid() | "(1, 1.33333)" (float precision) |

### 5. Deliverables
- [x] Point2D.h/.cpp - Component class (float, silent)
- [x] Triangle.h - Header with class declaration
- [x] Triangle.cpp - Implementation with 5 constructors
- [x] Main.cpp - Demonstration program

### 6. Geometric Calculations
- **isValid**: triangle inequality (a + b > c, etc.)
- **getType**: equilateral, isosceles, right, scalene
- **area**: cross product `|x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2`
- **centroid**: `((x1+x2+x3)/3, (y1+y2+y3)/3)` with float precision
