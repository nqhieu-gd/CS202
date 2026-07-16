#include "Date.h"
#include <ctime>

const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int cumDays[]   = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

bool Date::isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) {
    if (m == 2 && isLeapYear(y)) return 29;
    return monthDays[m - 1];
}

long Date::dateToDays(int d, int m, int y) {
    long yMinus1 = y - 1;
    long total = yMinus1 * 365 + yMinus1 / 4 - yMinus1 / 100 + yMinus1 / 400;
    total += cumDays[m - 1];
    if (m > 2 && isLeapYear(y)) total++;
    total += d;
    return total;
}

void Date::daysToDate(long n, int& d, int& m, int& y) {
    if (n < 1) {
        std::cerr << "Error: Date does not accept year before 1 (Gregorian calendar starts at year 1)\n";
        d = 1; m = 1; y = 1; return;
    }

    y = (int)(n / 366) + 1;

    long beforeY = dateToDays(0, 1, y);

    while (beforeY >= n) {
        y--;
        beforeY = dateToDays(0, 1, y);
    }
    while (beforeY + (isLeapYear(y) ? 366 : 365) < n) {
        beforeY += (isLeapYear(y) ? 366 : 365);
        y++;
    }

    int dayOfYear = (int)(n - beforeY);
    bool afterFeb = (dayOfYear > 31 + 28);

    m = 1;
    while (m < 12 && dayOfYear > cumDays[m] + (afterFeb && isLeapYear(y) ? 1 : 0))
        m++;

    d = dayOfYear - cumDays[m - 1] - (m > 2 && afterFeb && isLeapYear(y) ? 1 : 0);
}

Date::Date() {
    time_t t = time(0);
    tm local;
    localtime_s(&local, &t);
    day = local.tm_mday;
    month = local.tm_mon + 1;
    year = local.tm_year + 1900;
}

Date::Date(int y) : day(1), month(1), year(1) {
    if (y < 1) {
        std::cerr << "Error: Year " << y << " is invalid. Using year 1.\n";
        return;
    }
    year = y;
}

Date::Date(int y, int m) : day(1), month(1), year(1) {
    if (y < 1) {
        std::cerr << "Error: Year " << y << " is invalid. Using year 1.\n";
        return;
    }
    if (m < 1 || m > 12) {
        std::cerr << "Error: Month " << m << " is invalid. Using month 1.\n";
        year = y;
        return;
    }
    year = y;
    month = m;
}

Date::Date(int y, int m, int d) : day(1), month(1), year(1) {
    if (y < 1) {
        std::cerr << "Error: Year " << y << " is invalid. Using year 1.\n";
        return;
    }
    if (m < 1 || m > 12) {
        std::cerr << "Error: Month " << m << " is invalid. Using month 1, year " << y << ".\n";
        year = y;
        return;
    }
    if (d < 1 || d > daysInMonth(m, y)) {
        std::cerr << "Error: Day " << d << " is invalid for " << d << "/" << m << "/" << y
                  << ". Using day 1.\n";
        year = y; month = m;
        return;
    }
    year = y; month = m; day = d;
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

Date& Date::operator=(const Date& other) {
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
}

Date Date::Tomorrow() const {
    long days = dateToDays(day, month, year) + 1;
    int d, m, y;
    daysToDate(days, d, m, y);
    return Date(y, m, d);
}

Date Date::Yesterday() const {
    long days = dateToDays(day, month, year) - 1;
    int d, m, y;
    daysToDate(days, d, m, y);
    return Date(y, m, d);
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator>(const Date& other) const {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>=(const Date& other) const {
    return (*this == other) || (*this > other);
}

bool Date::operator<=(const Date& other) const {
    return (*this == other) || (*this < other);
}

Date Date::operator+(int days) const {
    long total = dateToDays(day, month, year) + days;
    int d, m, y;
    daysToDate(total, d, m, y);
    return Date(y, m, d);
}

Date Date::operator-(int days) const {
    return *this + (-days);
}

Date& Date::operator++() {
    *this = *this + 1;
    return *this;
}

Date Date::operator++(int) {
    Date temp(*this);
    *this = *this + 1;
    return temp;
}

Date& Date::operator--() {
    *this = *this - 1;
    return *this;
}

Date Date::operator--(int) {
    Date temp(*this);
    *this = *this - 1;
    return temp;
}

Date& Date::operator+=(int days) {
    *this = *this + days;
    return *this;
}

Date& Date::operator-=(int days) {
    *this = *this - days;
    return *this;
}

Date::operator int() const {
    int total = cumDays[month - 1];
    if (month > 2 && isLeapYear(year)) total++;
    total += day;
    return total;
}

Date::operator long() const {
    return dateToDays(day, month, year);
}

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    if (dt.day < 10) os << '0';
    os << dt.day << '/';
    if (dt.month < 10) os << '0';
    os << dt.month << '/' << dt.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& dt) {
    int d, m, y;
    char slash1, slash2;
    is >> d >> slash1 >> m >> slash2 >> y;
    if (y < 1 || m < 1 || m > 12 || d < 1 || d > Date::daysInMonth(m, y)) {
        std::cerr << "Error: Invalid date entered. Keeping original value.\n";
        return is;
    }
    dt.day = d;
    dt.month = m;
    dt.year = y;
    return is;
}
