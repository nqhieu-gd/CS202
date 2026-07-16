#include "SavingBankAccount.h"

int main() {
    std::cout << "=== BankAccount: 5 Constructors ===" << std::endl;

    BankAccount b1;
    BankAccount b2("ACC001", "Alice", "ID123", 500000);
    BankAccount b3(b2);
    BankAccount b4("ACC002", "Bob");
    BankAccount b5("ACC003");

    std::cout << "\nB2 (Full):" << std::endl;
    b2.displayInfo();

    std::cout << "\n=== BankAccount: deposit/withdraw ===" << std::endl;
    b2.deposit(200000);
    b2.withdraw(100000);
    std::cout << "Final balance: " << b2.checkBalance() << " VND" << std::endl;

    std::cout << "\n=== SavingBankAccount: 5 Constructors ===" << std::endl;

    SavingBankAccount s1;
    SavingBankAccount s2("SA001", "Charlie", "ID456", 1000000, 0.06, 12, 3);
    SavingBankAccount s3(s2);
    SavingBankAccount s4("SA002", "Diana", 0.06, 6, 2);
    SavingBankAccount s5("SA003", 0.07, 3, 1);

    std::cout << "\nS2 (Full):" << std::endl;
    s2.displayInfo();
    std::cout << "Check balance (with interest): " << s2.checkBalance() << " VND" << std::endl;
    std::cout << "Check interest only: " << s2.checkInterest() << " VND" << std::endl;

    std::cout << "\n=== Deposit guard (savingMonths < period) ===" << std::endl;
    s2.deposit(500000);

    std::cout << "\n=== Withdraw guard (savingMonths < period) ===" << std::endl;
    s2.withdraw(200000);

    std::cout << "\n=== withdrawImmediately ===" << std::endl;
    s2.withdrawImmediately(200000);
    s2.displayInfo();

    std::cout << "\n=== Verify balance unchanged by checkBalance ===" << std::endl;
    SavingBankAccount s6("SA004", "Eve", "ID789", 2000000, 0.06, 12, 6);
    std::cout << "Balance field: " << s6.checkBalance() << " VND" << std::endl;
    std::cout << "Balance field again (same): " << s6.checkBalance() << " VND" << std::endl;

    std::cout << "\n=== Polymorphism ===" << std::endl;
    BankAccount* accounts[] = { &b2, &s6 };
    for (BankAccount* a : accounts) {
        a->displayInfo();
        std::cout << "---" << std::endl;
    }

    return 0;
}
