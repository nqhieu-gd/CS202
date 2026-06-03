#pragma once
#include "Date.h"
#include "Book.h"
#include <string>

class Reader {
private:
    std::string code;
    std::string name;
    std::string idNumber;
    Date dob;
    std::string email;
    std::string address;
    std::string gender;
    Date creatingCardDay;
    Date expiringCardDay;
    Book borrowBook[6];
    int quantityOfBorrowing;
    Date borrowDay[6];
    Date returnDay[6];

    // Helper methods
    bool isValidCode(const std::string& c) const;
    bool isValidID(const std::string& id) const;
    bool isValidCharacter(const std::string& str) const;
    void toUpperCase(std::string& str);

public:
    // Constructors
    Reader();
    Reader(const std::string& code, const std::string& name, const std::string& idNum,
           const Date& birthDate, const std::string& gen, const std::string& mail,
           const std::string& addr, const Date& createDay);
    Reader(const Reader& other);
    Reader& operator=(const Reader& other);

    // Getters
    std::string getCode() const;
    std::string getName() const;
    std::string getIdNumber() const;
    Date getDob() const;
    std::string getEmail() const;
    std::string getAddress() const;
    std::string getGender() const;
    Date getCreatingCardDay() const;
    Date getExpiringCardDay() const;
    int getQuantityOfBorrowing() const;
    Book getBorrowBook(int index) const;
    Date getBorrowDay(int index) const;
    Date getReturnDay(int index) const;

    // Setters
    void setCode(const std::string& c);
    void setName(const std::string& n);
    void setIdNumber(const std::string& id);
    void setDob(const Date& d);
    void setEmail(const std::string& e);
    void setAddress(const std::string& a);
    void setGender(const std::string& g);
    void setCreatingCardDay(const Date& d);

    // Business methods
    void input();
    void display() const;
    bool canBorrowMore() const;
    void borrowBookFromLibrary(const Book& book, const Date& borrowDate, const Date& returnDate);
    void returnBookToLibrary(int bookIndex);
    bool hasOverdueBooks(const Date& today) const;
    void displayBorrowedBooks() const;
};
