#include "Point.cpp"
#include "Vector.cpp"
#include "Triangle.cpp"

int main() {
    Point A(0, 0);
    Point B(3, 4);
    Point C(6, 0);

    std::cout << "Point A: ";
    A.display();
    std::cout << "Point B: ";
    B.display();
    std::cout << "Point C: ";
    C.display();

    std::cout << "Distance from A to B: " << A.distance(B) << '\n';
    std::cout << "Distance from A to Ox: " << A.disToOx() << '\n';
    std::cout << "Distance from A to Oy: " << A.disToOy() << '\n';

    Triangle T(A, B, C);
    T.display();
    std::cout << "Triangle type: ";
    T.outputType();

    return 0;
}