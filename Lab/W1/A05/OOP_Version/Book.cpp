#include "Book.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

Book::Book() : ISBN(""), nameOfBook(""), nameOfAuthor(""), publisher(""),
               publishingYear(2000), typeOfBook(""), priceOfBook(0), theNumberOfBooks(0) {}

Book::Book(const std::string& isbn, const std::string& name, const std::string& author,
           const std::string& pub, int year, const std::string& type, long price, int quantity)
    : ISBN(isbn), nameOfBook(name), nameOfAuthor(author), publisher(pub),
      publishingYear(year), typeOfBook(type), priceOfBook(price), theNumberOfBooks(quantity) {}

Book::Book(const Book& other)
    : ISBN(other.ISBN), nameOfBook(other.nameOfBook), nameOfAuthor(other.nameOfAuthor),
      publisher(other.publisher), publishingYear(other.publishingYear),
      typeOfBook(other.typeOfBook), priceOfBook(other.priceOfBook),
      theNumberOfBooks(other.theNumberOfBooks) {}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        ISBN = other.ISBN;
        nameOfBook = other.nameOfBook;
        nameOfAuthor = other.nameOfAuthor;
        publisher = other.publisher;
        publishingYear = other.publishingYear;
        typeOfBook = other.typeOfBook;
        priceOfBook = other.priceOfBook;
        theNumberOfBooks = other.theNumberOfBooks;
    }
    return *this;
}

// Getters
std::string Book::getISBN() const { return ISBN; }
std::string Book::getNameOfBook() const { return nameOfBook; }
std::string Book::getNameOfAuthor() const { return nameOfAuthor; }
std::string Book::getPublisher() const { return publisher; }
int Book::getPublishingYear() const { return publishingYear; }
std::string Book::getTypeOfBook() const { return typeOfBook; }
long Book::getPriceOfBook() const { return priceOfBook; }
int Book::getTheNumberOfBooks() const { return theNumberOfBooks; }

// Setters
void Book::setISBN(const std::string& isbn) { ISBN = isbn; }
void Book::setNameOfBook(const std::string& name) { nameOfBook = name; }
void Book::setNameOfAuthor(const std::string& author) { nameOfAuthor = author; }
void Book::setPublisher(const std::string& pub) { publisher = pub; }
void Book::setPublishingYear(int year) { publishingYear = year; }
void Book::setTypeOfBook(const std::string& type) { typeOfBook = type; }
void Book::setPriceOfBook(long price) { priceOfBook = price; }
void Book::setTheNumberOfBooks(int quantity) { theNumberOfBooks = quantity; }

bool Book::isValidISBN(const std::string& isbn) const {
    if (isbn.length() != 10) return false;
    for (char c : isbn) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool Book::isValidCharacter(const std::string& str) const {
    for (char c : str) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

void Book::toUpperCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void Book::input() {
    char buffer[100];
    
    printf("ISBN OF BOOK (10 NUMBERS): ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    ISBN = buffer;
    
    while (!isValidISBN(ISBN)) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        ISBN = buffer;
    }

    printf("NAME OF BOOK: ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    nameOfBook = buffer;
    
    while (!isValidCharacter(nameOfBook) || nameOfBook.length() > 50) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        nameOfBook = buffer;
    }
    toUpperCase(nameOfBook);

    printf("NAME OF AUTHOR: ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    nameOfAuthor = buffer;
    
    while (!isValidCharacter(nameOfAuthor) || nameOfAuthor.length() > 50) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        nameOfAuthor = buffer;
    }
    toUpperCase(nameOfAuthor);

    printf("PUBLISHER: ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    publisher = buffer;
    
    while (!isValidCharacter(publisher) || publisher.length() > 50) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        publisher = buffer;
    }
    toUpperCase(publisher);

    printf("FILL PUBLISHING YEAR: ");
    scanf("%d", &publishingYear);
    while (publishingYear < 1900) {
        printf("FILL AGAIN: ");
        scanf("%d", &publishingYear);
    }

    printf("TYPE OF BOOK: ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    typeOfBook = buffer;
    
    while (!isValidCharacter(typeOfBook) || typeOfBook.length() > 40) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        typeOfBook = buffer;
    }
    toUpperCase(typeOfBook);

    printf("PRICE OF BOOK: ");
    scanf("%ld", &priceOfBook);
    while (priceOfBook < 0 || priceOfBook > 10000000) {
        printf("FILL AGAIN: ");
        scanf("%ld", &priceOfBook);
    }

    printf("THE QUANTITY: ");
    scanf("%d", &theNumberOfBooks);
    while (theNumberOfBooks < 0 || theNumberOfBooks > 1000000) {
        printf("FILL AGAIN: ");
        scanf("%d", &theNumberOfBooks);
    }
}

void Book::display() const {
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || %-10ld  || %-10d ||\n",
           ISBN.c_str(), nameOfBook.c_str(), nameOfAuthor.c_str(), publisher.c_str(),
           publishingYear, typeOfBook.c_str(), priceOfBook, theNumberOfBooks);
}

void Book::adjustQuantity(int delta) {
    theNumberOfBooks += delta;
    if (theNumberOfBooks < 0) theNumberOfBooks = 0;
}

bool Book::isAvailable() const {
    return theNumberOfBooks > 0;
}
