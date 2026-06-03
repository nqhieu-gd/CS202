#pragma once
#include "Book.h"
#include "Reader.h"
#include "Date.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> listBook;
    std::vector<Reader> listReader;

    // Helper methods for file I/O
    void readBooksFromFile(const std::string& filename);
    void writeBooksToFile(const std::string& filename);
    void readReadersFromFile(const std::string& filename);
    void writeReadersToFile(const std::string& filename);

public:
    // Constructors
    Library();
    
    // Book Management
    void printListOfBooks();
    void addBook();
    void adjustBook();
    void deleteBook();
    void findBookByISBN();
    void findBookByName();
    int getNumberOfBooks() const;
    Book& getBook(int index);

    // Reader Management
    void printListOfReaders();
    void addReader();
    void adjustReader();
    void deleteReader();
    void findReaderByCitizenId();
    void findBooksByReaderName();
    int getNumberOfReaders() const;
    Reader& getReader(int index);

    // Borrow/Return Operations
    void borrowBook(const Date& today);
    void returnBook(const Date& today);

    // Statistics
    void statisticsNumberOfBooks();
    void statisticsNumberOfBooksByType();
    void statisticsNumberOfReaders();
    void statisticsGender();
    void statisticsBooksBorrowed();
    void statisticsOverdueReaders(const Date& today);

    // File Operations
    void loadData();
    void saveData();
};
