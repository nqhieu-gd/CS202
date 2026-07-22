#pragma once
#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int d, int m, int y);
    void display() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};
