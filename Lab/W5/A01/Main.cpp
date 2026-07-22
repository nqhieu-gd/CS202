#include "OfficeEmployee.h"
#include "Worker.h"
#include "Company.h"

int main() {
    std::cout << "=== OfficeEmployee: 5 Constructors ===" << std::endl;

    OfficeEmployee oe1;
    OfficeEmployee oe2("E001", "Alice", Date(15, 3, 2020), "123 Main St", 22);
    OfficeEmployee oe3(oe2);
    OfficeEmployee oe4("E002", Date(1, 6, 2021), 20);
    OfficeEmployee oe5("E003 || Bob || 10/05/2019 || 456 Oak Ave || 18");

    std::cout << "\nOE2 (Full):" << std::endl;
    oe2.displayInfo();
    std::cout << "\nOE5 (String):" << std::endl;
    oe5.displayInfo();

    std::cout << "\n=== Worker: 5 Constructors ===" << std::endl;

    Worker w1;
    Worker w2("W001", "Charlie", Date(20, 8, 2022), "789 Pine Rd", 500);
    Worker w3(w2);
    Worker w4("W002", Date(5, 1, 2023), 350);
    Worker w5("W003 || Diana || 12/11/2020 || 321 Elm St || 420");

    std::cout << "\nW2 (Full):" << std::endl;
    w2.displayInfo();
    std::cout << "\nW5 (String):" << std::endl;
    w5.displayInfo();

    std::cout << "\n=== Polymorphism ===" << std::endl;
    Employee* employees[] = { &oe2, &oe5, &w2, &w5 };
    for (Employee* e : employees) {
        e->displayInfo();
        std::cout << "---" << std::endl;
    }

    std::cout << "\n=== Company Test ===" << std::endl;
    Company company;
    company.addEmployee(oe2.clone());
    company.addEmployee(oe5.clone());
    company.addEmployee(w2.clone());
    company.addEmployee(w5.clone());

    std::cout << "\n--- All Employees ---" << std::endl;
    company.displayEmployees();

    std::cout << "\n--- Salaries & Total ---" << std::endl;
    company.displaySalaries();

    std::cout << "\n--- Best Paid ---" << std::endl;
    company.bestPaidEmployees();

    Company copy(company);
    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    copy.displaySalaries();

    return 0;
}
