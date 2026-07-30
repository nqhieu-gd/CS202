#include <iostream>
#include <stdexcept>
#include <sstream>
#include "MyVector.h"

// ----------------------------------------------------
// Helper Fraction Class to test MyVector<Fraction>
// ----------------------------------------------------
class Fraction {
private:
    int num;
    int den;

    int gcd(int a, int b) const {
        return b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b);
    }

    void simplify() {
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        if (g > 0) { num /= g; den /= g; }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d == 0 ? 1 : d) {
        simplify();
    }

    bool operator==(const Fraction& other) const {
        return num == other.num && den == other.den;
    }

    bool operator!=(const Fraction& other) const { return !(*this == other); }

    bool operator<(const Fraction& other) const {
        return num * other.den < other.num * den;
    }

    bool operator<=(const Fraction& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Fraction& other) const { return !(*this <= other); }
    bool operator>=(const Fraction& other) const { return !(*this < other); }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if (f.den == 1) os << f.num;
        else os << f.num << "/" << f.den;
        return os;
    }
};



int main() {
    std::cout << "========================================\n";
    std::cout << "       TESTING MYVECTOR<INT>            \n";
    std::cout << "========================================\n\n";

    MyVector<int> v1;
    std::cout << "1. Initial empty vector v1: " << v1.toString() << " | Size: " << v1.getSize() << "\n";

    std::cout << "2. Adding elements (10, 20, 30, 20, 50):\n";
    v1.add(10);
    v1.add(20);
    v1.add(30);
    v1.add(20);
    v1.add(50);
    std::cout << "   v1: " << v1.toString() << " | Size: " << v1.getSize() << "\n";

    std::cout << "3. Testing addRange ({60, 70, 80}):\n";
    int arr[3] = {60, 70, 80};
    v1.addRange(arr, 3);
    std::cout << "   v1: " << v1.toString() << " | Size: " << v1.getSize() << "\n";

    std::cout << "4. Testing getItem and setItem:\n";
    std::cout << "   Item at index 2: " << v1.getItem(2) << "\n";
    v1.setItem(99, 2);
    std::cout << "   After setting index 2 to 99: " << v1.toString() << "\n";

    std::cout << "5. Testing contains, indexOf, lastIndexOf:\n";
    std::cout << "   Contains 20? " << (v1.contains(20) ? "Yes" : "No") << "\n";
    std::cout << "   First index of 20: " << v1.indexOf(20) << "\n";
    std::cout << "   Last index of 20: " << v1.lastIndexOf(20) << "\n";

    std::cout << "6. Testing insert(15 at index 1) and remove(20):\n";
    v1.insert(15, 1);
    std::cout << "   After insert 15 at index 1: " << v1.toString() << "\n";
    v1.remove(20);
    std::cout << "   After removing first 20:   " << v1.toString() << "\n";
    v1.removeAt(0);
    std::cout << "   After removeAt(0):         " << v1.toString() << "\n";

    std::cout << "7. Testing reverse:\n";
    v1.reverse();
    std::cout << "   Reversed v1: " << v1.toString() << "\n";

    std::cout << "8. Testing sortAsc and sortDesc:\n";
    v1.sortAsc();
    std::cout << "   Sorted Ascending:  " << v1.toString() << "\n";
    v1.sortDesc();
    std::cout << "   Sorted Descending: " << v1.toString() << "\n";

    std::cout << "\n========================================\n";
    std::cout << "     TESTING MYVECTOR<FRACTION>         \n";
    std::cout << "========================================\n\n";

    MyVector<Fraction> vFrac;
    vFrac.add(Fraction(1, 2));
    vFrac.add(Fraction(3, 4));
    vFrac.add(Fraction(1, 4));
    vFrac.add(Fraction(5, 6));

    std::cout << "1. Initial Fraction vector: " << vFrac.toString() << "\n";
    vFrac.sortAsc();
    std::cout << "2. Fractions sorted Ascending:  " << vFrac.toString() << "\n";
    vFrac.sortDesc();
    std::cout << "3. Fractions sorted Descending: " << vFrac.toString() << "\n";

    std::cout << "\n========================================\n";
    std::cout << "      TESTING EXCEPTION HANDLING        \n";
    std::cout << "========================================\n\n";

    try {
        std::cout << "Attempting to create MyVector with negative size (-5)...\n";
        MyVector<int> vBad(-5);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    try {
        std::cout << "Attempting getItem at invalid index 100...\n";
        v1.getItem(100);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\nAll tests completed successfully!\n";
    return 0;
}
