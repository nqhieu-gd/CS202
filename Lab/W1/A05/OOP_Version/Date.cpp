#include "Date.h"
#include <iostream>
#include <cstdio>

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

void Date::input() {
    printf("YEAR: ");
    scanf("%d", &year);
    while (year < 2000) {
        printf("FILL AGAIN: ");
        scanf("%d", &year);
    }
    
    printf("MONTH: ");
    scanf("%d", &month);
    while (month <= 0 || month > 12) {
        printf("FILL AGAIN: ");
        scanf("%d", &month);
    }
    
    int maxDays = 31;
    if (month == 2) {
        maxDays = isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }
    
    printf("DAY: ");
    scanf("%d", &day);
    while (day <= 0 || day > maxDays) {
        printf("FILL AGAIN: ");
        scanf("%d", &day);
    }
}

void Date::display() const {
    printf("%d-%d-%d", day, month, year);
}

bool Date::isValidDate(int d, int m, int y) {
    if (y < 1900 || m < 1 || m > 12 || d < 1) return false;
    int maxDays = 31;
    if (m == 2) {
        maxDays = isLeapYear(y) ? 29 : 28;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        maxDays = 30;
    }
    return d <= maxDays;
}

bool Date::isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool Date::isAfter(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool Date::isBefore(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

int Date::daysDifference(const Date& other) const {
    // Simple approximation
    int days1 = year * 365 + month * 30 + day;
    int days2 = other.year * 365 + other.month * 30 + other.day;
    return days1 - days2;
}
