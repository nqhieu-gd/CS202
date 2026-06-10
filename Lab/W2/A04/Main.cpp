#include "Student.h"

int main() {
    cout << "=== Testing Student Constructors ===" << endl << endl;

    cout << "1. Creating s1 with default constructor:" << endl;
    Student s1;
    s1.display();
    cout << "toString: " << s1.toString() << endl << endl;

    cout << "2. Creating s2 with full info:" << endl;
    Student s2(101, "Nguyen Van A", "123 Le Loi, Q1, HCMC", 3.75);
    s2.display();
    cout << "toString: " << s2.toString() << endl << endl;

    cout << "3. Creating s3 with different info:" << endl;
    Student s3(102, "Tran Thi B", "456 Nguyen Hue, Q1, HCMC", 3.92);
    s3.display();
    cout << "toString: " << s3.toString() << endl << endl;

    cout << "4. Creating s4 as copy of s2:" << endl;
    Student s4(s2);
    s4.display();
    cout << "toString: " << s4.toString() << endl << endl;

    cout << "5. Creating s5 from string \"103|Le Van C|789 Pasteur, Q3, HCMC|3.50\":" << endl;
    Student s5("103|Le Van C|789 Pasteur, Q3, HCMC|3.50");
    s5.display();
    cout << "toString: " << s5.toString() << endl << endl;

    cout << "6. Cloning s3:" << endl;
    Student s6 = s3.clone();
    s6.display();
    cout << "toString: " << s6.toString() << endl << endl;

    cout << "7. Creating s7 with id=201 and name=\"Nguyen Van D\":" << endl;
    Student s7(201, "Nguyen Van D");
    s7.display();
    cout << "toString: " << s7.toString() << endl << endl;

    cout << "8. Testing copy assignment s2 = s3:" << endl;
    s2 = s3;
    cout << "s2 after assignment: " << s2.toString() << endl << endl;

    cout << "=== Program ending (destructors will be called) ===" << endl;

    return 0;
}
