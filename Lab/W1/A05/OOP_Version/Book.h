#pragma once
#include <string>

class Book {
private:
    std::string ISBN;
    std::string nameOfBook;
    std::string nameOfAuthor;
    std::string publisher;
    int publishingYear;
    std::string typeOfBook;
    long priceOfBook;
    int theNumberOfBooks;

    // Helper methods
    bool isValidISBN(const std::string& isbn) const;
    bool isValidCharacter(const std::string& str) const;
    void toUpperCase(std::string& str);

public:
    // Constructors
    Book();
    Book(const std::string& isbn, const std::string& name, const std::string& author,
         const std::string& pub, int year, const std::string& type, long price, int quantity);
    Book(const Book& other);
    Book& operator=(const Book& other);

    // Getters
    std::string getISBN() const;
    std::string getNameOfBook() const;
    std::string getNameOfAuthor() const;
    std::string getPublisher() const;
    int getPublishingYear() const;
    std::string getTypeOfBook() const;
    long getPriceOfBook() const;
    int getTheNumberOfBooks() const;

    // Setters
    void setISBN(const std::string& isbn);
    void setNameOfBook(const std::string& name);
    void setNameOfAuthor(const std::string& author);
    void setPublisher(const std::string& pub);
    void setPublishingYear(int year);
    void setTypeOfBook(const std::string& type);
    void setPriceOfBook(long price);
    void setTheNumberOfBooks(int quantity);

    // Business methods
    void input();
    void display() const;
    void adjustQuantity(int delta);
    bool isAvailable() const;
};
