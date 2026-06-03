#include "Library.h"
#include "Date.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

void printMainMenu() {
    printf("\n========================================\n");
    printf("    LIBRARY MANAGEMENT SYSTEM (OOP)    \n");
    printf("========================================\n");
    printf("1. Book Management\n");
    printf("2. Reader Management\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Statistics\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Your choice: ");
}

void printBookMenu() {
    printf("\n=== BOOK MANAGEMENT ===\n");
    printf("a. Display all books\n");
    printf("b. Add new book\n");
    printf("c. Adjust book information\n");
    printf("d. Delete book\n");
    printf("e. Find book by ISBN\n");
    printf("f. Find book by name\n");
    printf("g. Back to main menu\n");
    printf("Your choice: ");
}

void printReaderMenu() {
    printf("\n=== READER MANAGEMENT ===\n");
    printf("a. Display all readers\n");
    printf("b. Add new reader\n");
    printf("c. Adjust reader information\n");
    printf("d. Delete reader\n");
    printf("e. Find reader by ID\n");
    printf("f. Find books by reader name\n");
    printf("g. Back to main menu\n");
    printf("Your choice: ");
}

void printStatisticsMenu() {
    printf("\n=== STATISTICS ===\n");
    printf("a. Number of books\n");
    printf("b. Number of books by type\n");
    printf("c. Number of readers\n");
    printf("d. Readers by gender\n");
    printf("e. Books borrowed\n");
    printf("f. Overdue readers\n");
    printf("g. Back to main menu\n");
    printf("Your choice: ");
}

int main() {
    Library library;
    Date today;
    bool running = true;

    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n");
    printf("Please enter today's date:\n");
    today.input();
    system("cls");

    library.loadData();

    while (running) {
        printMainMenu();
        char choice;
        scanf("\n%c", &choice);
        system("cls");

        switch (choice) {
        case '1': {
            // Book Management
            bool bookMenu = true;
            while (bookMenu) {
                printBookMenu();
                char bookChoice;
                scanf("\n%c", &bookChoice);
                system("cls");

                switch (bookChoice) {
                case 'a':
                    library.printListOfBooks();
                    break;
                case 'b':
                    library.addBook();
                    break;
                case 'c':
                    library.adjustBook();
                    break;
                case 'd':
                    library.deleteBook();
                    break;
                case 'e':
                    library.findBookByISBN();
                    break;
                case 'f':
                    library.findBookByName();
                    break;
                case 'g':
                    bookMenu = false;
                    break;
                default:
                    printf("Invalid choice!\n");
                }
                system("cls");
            }
            break;
        }

        case '2': {
            // Reader Management
            bool readerMenu = true;
            while (readerMenu) {
                printReaderMenu();
                char readerChoice;
                scanf("\n%c", &readerChoice);
                system("cls");

                switch (readerChoice) {
                case 'a':
                    library.printListOfReaders();
                    break;
                case 'b':
                    library.addReader();
                    break;
                case 'c':
                    library.adjustReader();
                    break;
                case 'd':
                    library.deleteReader();
                    break;
                case 'e':
                    library.findReaderByCitizenId();
                    break;
                case 'f':
                    library.findBooksByReaderName();
                    break;
                case 'g':
                    readerMenu = false;
                    break;
                default:
                    printf("Invalid choice!\n");
                }
                system("cls");
            }
            break;
        }

        case '3':
            library.borrowBook(today);
            break;

        case '4':
            library.returnBook(today);
            break;

        case '5': {
            // Statistics
            bool statsMenu = true;
            while (statsMenu) {
                printStatisticsMenu();
                char statsChoice;
                scanf("\n%c", &statsChoice);
                system("cls");

                switch (statsChoice) {
                case 'a':
                    library.statisticsNumberOfBooks();
                    break;
                case 'b':
                    library.statisticsNumberOfBooksByType();
                    break;
                case 'c':
                    library.statisticsNumberOfReaders();
                    break;
                case 'd':
                    library.statisticsGender();
                    break;
                case 'e':
                    library.statisticsBooksBorrowed();
                    break;
                case 'f':
                    library.statisticsOverdueReaders(today);
                    break;
                case 'g':
                    statsMenu = false;
                    break;
                default:
                    printf("Invalid choice!\n");
                }
                system("cls");
            }
            break;
        }

        case '6':
            library.saveData();
            printf("Thank you for using Library Management System!\n");
            running = false;
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            system("pause");
            system("cls");
        }
    }

    return 0;
}
