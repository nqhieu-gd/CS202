#include "MyIntArray.h"

int main() {
    cout << "=== Testing MyIntArray Constructors ===" << endl << endl;

    cout << "1. Creating arr1 with default constructor:" << endl;
    MyIntArray arr1;
    arr1.display();
    cout << "toString: " << arr1.toString() << endl << endl;

    cout << "2. Creating arr2 with size 5:" << endl;
    MyIntArray arr2(5);
    arr2.display();
    cout << "toString: " << arr2.toString() << endl << endl;

    cout << "3. Creating arr3 with array {3, 1, 4, 1, 5, 9}:" << endl;
    int data[] = {3, 1, 4, 1, 5, 9};
    MyIntArray arr3(6, data);
    arr3.display();
    cout << "toString: " << arr3.toString() << endl;
    cout << "Sum: " << arr3.sum() << endl;
    cout << "Max: " << arr3.max() << endl;
    cout << "Min: " << arr3.min() << endl << endl;

    cout << "4. Creating arr4 as copy of arr3:" << endl;
    MyIntArray arr4(arr3);
    arr4.display();
    cout << "toString: " << arr4.toString() << endl << endl;

    cout << "5. Creating arr5 from string \"10,20,30,40,50\":" << endl;
    MyIntArray arr5("10,20,30,40,50");
    arr5.display();
    cout << "toString: " << arr5.toString() << endl << endl;

    cout << "6. Cloning arr3:" << endl;
    MyIntArray arr6 = arr3.clone();
    arr6.display();
    cout << "toString: " << arr6.toString() << endl << endl;

    cout << "7. Sorting arr3:" << endl;
    cout << "Before sort: " << arr3.toString() << endl;
    arr3.sortAsc();
    cout << "After sort: " << arr3.toString() << endl << endl;

    cout << "8. Testing copy assignment arr6 = arr5:" << endl;
    arr6 = arr5;
    cout << "arr6 after assignment: " << arr6.toString() << endl << endl;

    cout << "9. Creating arr7 from empty string:" << endl;
    MyIntArray arr7("");
    cout << "toString: " << arr7.toString() << endl;
    cout << "max: " << arr7.max() << ", min: " << arr7.min() << endl << endl;

    cout << "=== Program ending (destructors will be called) ===" << endl;

    return 0;
}
