#include "Drawing.h"
#include "Point.h"

class Triangle : public geometry {
private:
    point2D p1, p2, p3;
public:
    void draw() override;

    Triangle(point2D p1, point2D p2, point2D p3);
};

class Rectangle : public geometry {
private:
    point2D topLeft, bottomRight;
public:
    void input() override;
    void draw() override;

    Rectangle(point2D topLeft, point2D bottomRight);
};