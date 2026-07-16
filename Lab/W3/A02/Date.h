#pragma once
#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    static bool isLeapYear(int y);
    static int daysInMonth(int m, int y);
    static long dateToDays(int d, int m, int y);
    static void daysToDate(long n, int& d, int& m, int& y);

public:
    Date();
    Date(int y);
    Date(int y, int m);
    Date(int y, int m, int d);
    Date(const Date& other);

    Date& operator=(const Date& other);

    Date Tomorrow() const;
    Date Yesterday() const;

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;

    Date operator+(int days) const;
    Date operator-(int days) const;
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    Date& operator+=(int days);
    Date& operator-=(int days);

    operator int() const;
    operator long() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& dt);
    friend std::istream& operator>>(std::istream& is, Date& dt);
};
