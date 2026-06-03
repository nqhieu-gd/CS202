#include "Reader.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

Reader::Reader() : code(""), name(""), idNumber(""), dob(), email(""), address(""),
                   gender(""), creatingCardDay(), expiringCardDay(), quantityOfBorrowing(0) {
    for (int i = 0; i < 6; i++) {
        borrowBook[i] = Book();
        borrowDay[i] = Date();
        returnDay[i] = Date();
    }
}

Reader::Reader(const std::string& code, const std::string& name, const std::string& idNum,
               const Date& birthDate, const std::string& gen, const std::string& mail,
               const std::string& addr, const Date& createDay)
    : code(code), name(name), idNumber(idNum), dob(birthDate), email(mail), address(addr),
      gender(gen), creatingCardDay(createDay), quantityOfBorrowing(0) {
    expiringCardDay = Date(createDay.getDay(), createDay.getMonth(), createDay.getYear() + 4);
    for (int i = 0; i < 6; i++) {
        borrowBook[i] = Book();
        borrowDay[i] = Date();
        returnDay[i] = Date();
    }
}

Reader::Reader(const Reader& other)
    : code(other.code), name(other.name), idNumber(other.idNumber), dob(other.dob),
      email(other.email), address(other.address), gender(other.gender),
      creatingCardDay(other.creatingCardDay), expiringCardDay(other.expiringCardDay),
      quantityOfBorrowing(other.quantityOfBorrowing) {
    for (int i = 0; i < 6; i++) {
        borrowBook[i] = other.borrowBook[i];
        borrowDay[i] = other.borrowDay[i];
        returnDay[i] = other.returnDay[i];
    }
}

Reader& Reader::operator=(const Reader& other) {
    if (this != &other) {
        code = other.code;
        name = other.name;
        idNumber = other.idNumber;
        dob = other.dob;
        email = other.email;
        address = other.address;
        gender = other.gender;
        creatingCardDay = other.creatingCardDay;
        expiringCardDay = other.expiringCardDay;
        quantityOfBorrowing = other.quantityOfBorrowing;
        for (int i = 0; i < 6; i++) {
            borrowBook[i] = other.borrowBook[i];
            borrowDay[i] = other.borrowDay[i];
            returnDay[i] = other.returnDay[i];
        }
    }
    return *this;
}

// Getters
std::string Reader::getCode() const { return code; }
std::string Reader::getName() const { return name; }
std::string Reader::getIdNumber() const { return idNumber; }
Date Reader::getDob() const { return dob; }
std::string Reader::getEmail() const { return email; }
std::string Reader::getAddress() const { return address; }
std::string Reader::getGender() const { return gender; }
Date Reader::getCreatingCardDay() const { return creatingCardDay; }
Date Reader::getExpiringCardDay() const { return expiringCardDay; }
int Reader::getQuantityOfBorrowing() const { return quantityOfBorrowing; }
Book Reader::getBorrowBook(int index) const { return borrowBook[index]; }
Date Reader::getBorrowDay(int index) const { return borrowDay[index]; }
Date Reader::getReturnDay(int index) const { return returnDay[index]; }

// Setters
void Reader::setCode(const std::string& c) { code = c; }
void Reader::setName(const std::string& n) { name = n; }
void Reader::setIdNumber(const std::string& id) { idNumber = id; }
void Reader::setDob(const Date& d) { dob = d; }
void Reader::setEmail(const std::string& e) { email = e; }
void Reader::setAddress(const std::string& a) { address = a; }
void Reader::setGender(const std::string& g) { gender = g; }
void Reader::setCreatingCardDay(const Date& d) {
    creatingCardDay = d;
    expiringCardDay = Date(d.getDay(), d.getMonth(), d.getYear() + 4);
}

bool Reader::isValidCode(const std::string& c) const {
    if (c.length() != 8 || c[0] == '0') return false;
    for (char ch : c) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool Reader::isValidID(const std::string& id) const {
    if (id.length() != 12) return false;
    for (char ch : id) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool Reader::isValidCharacter(const std::string& str) const {
    for (char c : str) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

void Reader::toUpperCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void Reader::input() {
    char buffer[100];
    
    printf("CODE OF READER (YOUR ID STUDENT NUMBER): ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    code = buffer;
    
    while (!isValidCode(code)) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        code = buffer;
    }

    printf("NAME OF READER: ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    name = buffer;
    
    while (!isValidCharacter(name) || name.length() > 50) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        name = buffer;
    }
    toUpperCase(name);

    printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    idNumber = buffer;
    
    while (!isValidID(idNumber)) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        idNumber = buffer;
    }

    printf("FILL YOUR BIRTHDAY\n");
    dob.input();

    int choice;
    printf("PLEASE FILL 1 (MALE) OR FILL 0 (FEMALE): ");
    scanf("%d", &choice);
    while (choice != 0 && choice != 1) {
        printf("PLEASE FILL AGAIN: ");
        scanf("%d", &choice);
    }
    gender = (choice == 1) ? "MALE" : "FEMALE";

    printf("EMAIL OF READER: ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    email = buffer;
    
    while (email.length() > 50) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        email = buffer;
    }

    printf("ADDRESS OF READER (ADDRESS NUMBER, WARD, DISTRICT): ");
    scanf("\n");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    address = buffer;
    
    while (address.length() > 50) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        address = buffer;
    }

    printf("FILL YOUR CARD CREATING DAY\n");
    creatingCardDay.input();
    expiringCardDay = Date(creatingCardDay.getDay(), creatingCardDay.getMonth(),
                           creatingCardDay.getYear() + 4);
}

void Reader::display() const {
    printf("|| %-10s  ||  %-22s  ||  %-15s  ||   ", code.c_str(), name.c_str(), idNumber.c_str());
    dob.display();
    printf("  ||  %-7s  ||  %-30s  ||  %-40s  ||  ", gender.c_str(), email.c_str(), address.c_str());
    creatingCardDay.display();
    printf(" ||   ");
    expiringCardDay.display();
    printf("  ||\n");
}

bool Reader::canBorrowMore() const {
    return quantityOfBorrowing < 6;
}

void Reader::borrowBookFromLibrary(const Book& book, const Date& borrowDate, const Date& returnDate) {
    if (canBorrowMore()) {
        borrowBook[quantityOfBorrowing] = book;
        borrowDay[quantityOfBorrowing] = borrowDate;
        this->returnDay[quantityOfBorrowing] = returnDate;
        quantityOfBorrowing++;
    }
}

void Reader::returnBookToLibrary(int bookIndex) {
    if (bookIndex >= 0 && bookIndex < quantityOfBorrowing) {
        for (int i = bookIndex; i < quantityOfBorrowing - 1; i++) {
            borrowBook[i] = borrowBook[i + 1];
            borrowDay[i] = borrowDay[i + 1];
            returnDay[i] = returnDay[i + 1];
        }
        quantityOfBorrowing--;
    }
}

bool Reader::hasOverdueBooks(const Date& today) const {
    for (int i = 0; i < quantityOfBorrowing; i++) {
        if (today.isAfter(returnDay[i])) {
            return true;
        }
    }
    return false;
}

void Reader::displayBorrowedBooks() const {
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  ||\n",
           "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < quantityOfBorrowing; i++) {
        borrowBook[i].display();
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
    }
}
