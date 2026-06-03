#include "Library.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

Library::Library() {}

void Library::printListOfBooks() {
    printf("%110s\n", "LIST OF BOOKS IN LIBRARY");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || %-10s  || %-10s ||\n",
           "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE", "PRICE", "QUANTITY");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    for (size_t i = 0; i < listBook.size(); i++) {
        listBook[i].display();
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void Library::addBook() {
    Book newBook;
    bool flag = true;
    
    while (flag) {
        newBook.input();
        listBook.push_back(newBook);
        writeBooksToFile("listBook.txt");
        
        int choice;
        printf("1. CONTINUE FILLING INFORMATION\n");
        printf("2. STOP\n");
        printf("YOUR CHOICE: ");
        scanf("%d", &choice);
        
        flag = (choice == 1);
    }
}

void Library::deleteBook() {
    printListOfBooks();
    bool flag = true;
    
    while (flag && !listBook.empty()) {
        printf("BOOK THAT YOU WANT TO DELETE (1 to %zu): ", listBook.size());
        int choose;
        scanf("%d", &choose);
        
        if (choose > 0 && choose <= (int)listBook.size()) {
            listBook.erase(listBook.begin() + choose - 1);
            system("cls");
            printListOfBooks();
            writeBooksToFile("listBook.txt");
        }
        
        int choice;
        printf("DO YOU WANT TO CONTINUE DELETING?\n");
        printf("1. YES\n2. NO\n");
        scanf("%d", &choice);
        flag = (choice == 1);
    }
}

void Library::findBookByISBN() {
    printf("LIST ISBN OF BOOKS IN LIBRARY\n");
    for (size_t i = 0; i < listBook.size(); i++) {
        printf("%s\n", listBook[i].getISBN().c_str());
    }
    
    char buffer[20];
    printf("ISBN THAT YOU NEED TO FIND: ");
    scanf("\n");
    fgets(buffer, 20, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    std::string isbn = buffer;
    
    int index = -1;
    for (size_t i = 0; i < listBook.size(); i++) {
        if (listBook[i].getISBN() == isbn) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("CAN'T FIND ISBN!\n");
    } else {
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || %-10s  || %-10s ||\n",
               "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE", "PRICE", "QUANTITY");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        listBook[index].display();
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void Library::printListOfReaders() {
    printf("%110s\n", "LIST OF READERS IN LIBRARY");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-8s  ||  %-3s   ||  %-30s  ||  %-40s  ||  %-3s ||   %-3s  ||\n",
           "CODE", "FULL NAME", "ID NUMBER", "DATEOFBIRTH", "GENDER", "EMAIL", "ADDRESS", "CREATING", "EXPIRING");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    for (size_t i = 0; i < listReader.size(); i++) {
        listReader[i].display();
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void Library::addReader() {
    Reader newReader;
    bool flag = true;
    
    while (flag) {
        newReader.input();
        listReader.push_back(newReader);
        writeReadersToFile("listReader.txt");
        
        int choice;
        printf("1. CONTINUE FILLING INFORMATION\n");
        printf("2. STOP\n");
        printf("YOUR CHOICE: ");
        scanf("%d", &choice);
        
        flag = (choice == 1);
    }
}

void Library::deleteReader() {
    printListOfReaders();
    bool flag = true;
    
    while (flag && !listReader.empty()) {
        printf("READER WHOSE INFORMATION YOU WANT TO DELETE (1 to %zu): ", listReader.size());
        int choose;
        scanf("%d", &choose);
        
        if (choose > 0 && choose <= (int)listReader.size()) {
            listReader.erase(listReader.begin() + choose - 1);
            system("cls");
            printListOfReaders();
            writeReadersToFile("listReader.txt");
        }
        
        int choice;
        printf("DO YOU WANT TO CONTINUE DELETING?\n");
        printf("1. YES\n2. NO\n");
        scanf("%d", &choice);
        flag = (choice == 1);
    }
}

void Library::statisticsNumberOfBooks() {
    printf("TOTAL NUMBER OF BOOKS IN LIBRARY: %zu\n", listBook.size());
    system("pause");
}

void Library::statisticsNumberOfReaders() {
    printf("TOTAL NUMBER OF READERS: %zu\n", listReader.size());
    system("pause");
}

int Library::getNumberOfBooks() const {
    return listBook.size();
}

int Library::getNumberOfReaders() const {
    return listReader.size();
}

Book& Library::getBook(int index) {
    return listBook[index];
}

Reader& Library::getReader(int index) {
    return listReader[index];
}

void Library::loadData() {
    readBooksFromFile("listBook.txt");
    readReadersFromFile("listReader.txt");
}

void Library::saveData() {
    writeBooksToFile("listBook.txt");
    writeReadersToFile("listReader.txt");
}

// Simplified file I/O - basic implementation
void Library::readBooksFromFile(const std::string& filename) {
    // Simplified - would need proper CSV parsing in full implementation
    printf("Loading books from %s...\n", filename.c_str());
}

void Library::writeBooksToFile(const std::string& filename) {
    // Simplified - would write to CSV format
    printf("Saving books to %s...\n", filename.c_str());
}

void Library::readReadersFromFile(const std::string& filename) {
    // Simplified - would need proper CSV parsing
    printf("Loading readers from %s...\n", filename.c_str());
}

void Library::writeReadersToFile(const std::string& filename) {
    // Simplified - would write to CSV format
    printf("Saving readers to %s...\n", filename.c_str());
}

// Stub implementations for remaining methods
void Library::adjustBook() { printf("Adjust book - implementation needed\n"); }
void Library::findBookByName() { printf("Find book by name - implementation needed\n"); }
void Library::adjustReader() { printf("Adjust reader - implementation needed\n"); }
void Library::findReaderByCitizenId() { printf("Find reader - implementation needed\n"); }
void Library::findBooksByReaderName() { printf("Find books by reader - implementation needed\n"); }
void Library::borrowBook(const Date& today) { printf("Borrow book - implementation needed\n"); }
void Library::returnBook(const Date& today) { printf("Return book - implementation needed\n"); }
void Library::statisticsNumberOfBooksByType() { printf("Statistics by type - implementation needed\n"); }
void Library::statisticsGender() { printf("Statistics gender - implementation needed\n"); }
void Library::statisticsBooksBorrowed() { printf("Statistics borrowed - implementation needed\n"); }
void Library::statisticsOverdueReaders(const Date& today) { printf("Statistics overdue - implementation needed\n"); }
