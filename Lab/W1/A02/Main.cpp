#include "Point.cpp"
#include "Vector.cpp"
#include "Triangle.cpp"

void displayMenu() {
    std::cout << "\n===== POINT AND TRIANGLE CALCULATOR =====\n";
    std::cout << "1. Input three points\n";
    std::cout << "2. Display points\n";
    std::cout << "3. Calculate point distances\n";
    std::cout << "4. Create and display triangle\n";
    std::cout << "5. Check triangle validity\n";
    std::cout << "6. Determine triangle type\n";
    std::cout << "7. Calculate perimeter\n";
    std::cout << "8. Calculate area\n";
    std::cout << "9. Find centroid (center G)\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Point A, B, C;
    Triangle T;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nEnter point A:\n";
            A.input();
            std::cout << "Enter point B:\n";
            B.input();
            std::cout << "Enter point C:\n";
            C.input();
            T = Triangle(A, B, C);
            break;

        case 2:
            std::cout << "\nPoint A: ";
            A.display();
            std::cout << "Point B: ";
            B.display();
            std::cout << "Point C: ";
            C.display();
            break;

        case 3:
            std::cout << "\nDistance from A to B: " << A.distance(B) << '\n';
            std::cout << "Distance from B to C: " << B.distance(C) << '\n';
            std::cout << "Distance from C to A: " << C.distance(A) << '\n';
            std::cout << "\nDistance from A to Ox: " << A.disToOx() << '\n';
            std::cout << "Distance from A to Oy: " << A.disToOy() << '\n';
            std::cout << "Distance from B to Ox: " << B.disToOx() << '\n';
            std::cout << "Distance from B to Oy: " << B.disToOy() << '\n';
            std::cout << "Distance from C to Ox: " << C.disToOx() << '\n';
            std::cout << "Distance from C to Oy: " << C.disToOy() << '\n';
            break;

        case 4:
            T.display();
            break;

        case 5:
            if (T.isValid()) {
                std::cout << "\nThe triangle is VALID.\n";
            }
            else {
                std::cout << "\nThe triangle is INVALID (points are collinear or coincident).\n";
            }
            break;

        case 6:
            if (T.isValid()) {
                std::cout << "\nTriangle type: ";
                T.outputType();
            }
            else {
                std::cout << "\nCannot determine type - triangle is invalid.\n";
            }
            break;

        case 7:
            if (T.isValid()) {
                std::cout << "\nPerimeter: " << T.perimeter() << '\n';
            }
            else {
                std::cout << "\nCannot calculate perimeter - triangle is invalid.\n";
            }
            break;

        case 8:
            if (T.isValid()) {
                std::cout << "\nArea: " << T.area() << '\n';
            }
            else {
                std::cout << "\nCannot calculate area - triangle is invalid.\n";
            }
            break;

        case 9:
            if (T.isValid()) {
                Point G = T.centerG();
                std::cout << "\nCentroid (Center G): ";
                G.display();
            }
            else {
                std::cout << "\nCannot find centroid - triangle is invalid.\n";
            }
            break;

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}