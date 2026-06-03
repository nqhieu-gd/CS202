#pragma once

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructors
    Date();
    Date(int d, int m, int y);
    Date(const Date& other);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Input/Output
    void input();
    void display() const;

    // Validation
    static bool isValidDate(int d, int m, int y);
    static bool isLeapYear(int y);

    // Comparison
    bool isAfter(const Date& other) const;
    bool isBefore(const Date& other) const;
    int daysDifference(const Date& other) const;
};
