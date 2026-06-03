classDiagram
    Triangle o-- Point
    class Point {
        -double x
        -double y
        +Point()
        +Point(double x, double y)
        +input() void
        +display() void
        +distance(Point b) double
        +disToOx() double
        +disToOy() double
    }
    class Triangle {
        -Point A
        -Point B
        -Point C
        +Triangle()
        +Triangle(Point A, Point B, Point C)
        +input() void
        +display() void
        +isValid() bool
        +type() int
        +outputType() void
        +perimeter() double
        +area() double
        +centerG() Point
    }