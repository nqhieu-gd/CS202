#include "Fraction.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n===== FRACTION CALCULATOR =====\n";
    std::cout << "1. Input two fractions\n";
    std::cout << "2. Add fractions\n";
    std::cout << "3. Subtract fractions\n";
    std::cout << "4. Multiply fractions\n";
    std::cout << "5. Divide fractions\n";
    std::cout << "6. Compare fractions\n";
    std::cout << "7. Check fraction properties\n";
    std::cout << "8. Display fractions\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Fraction a, b, result;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nEnter first fraction:\n";
            a.input();
            std::cout << "Enter second fraction:\n";
            b.input();
            break;

        case 2:
            result = a;
            result.add(b);
            std::cout << "Result: ";
            a.display();
            std::cout << " + ";
            b.display();
            std::cout << " = ";
            result.display();
            break;

        case 3:
            result = a;
            result.subtract(b);
            std::cout << "Result: ";
            a.display();
            std::cout << " - ";
            b.display();
            std::cout << " = ";
            result.display();
            break;

        case 4:
            result = a;
            result.multiply(b);
            std::cout << "Result: ";
            a.display();
            std::cout << " * ";
            b.display();
            std::cout << " = ";
            result.display();
            break;

        case 5:
            try {
                result = a;
                result.divide(b);
                std::cout << "Result: ";
                a.display();
                std::cout << " / ";
                b.display();
                std::cout << " = ";
                result.display();
            }
            catch (const char* msg) {
                std::cerr << "Error: " << msg << std::endl;
            }
            break;

        case 6:
            std::cout << "Comparing fractions:\n";
            a.display();
            if (a.compare(b)) {
                std::cout << " >= ";
            }
            else {
                std::cout << " < ";
            }
            b.display();
            break;

        case 7:
            std::cout << "\nFirst fraction: ";
            a.display();
            if (a.isPositive()) std::cout << "  -> Positive\n";
            else if (a.isNegative()) std::cout << "  -> Negative\n";
            else if (a.isZero()) std::cout << "  -> Zero\n";

            std::cout << "Second fraction: ";
            b.display();
            if (b.isPositive()) std::cout << "  -> Positive\n";
            else if (b.isNegative()) std::cout << "  -> Negative\n";
            else if (b.isZero()) std::cout << "  -> Zero\n";
            break;

        case 8:
            std::cout << "\nFirst fraction: ";
            a.display();
            std::cout << "Second fraction: ";
            b.display();
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