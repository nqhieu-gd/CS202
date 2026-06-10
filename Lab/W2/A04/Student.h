#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    char* fullname;
    char* address;
    double gpa;

public:
    Student();
    Student(int id, const char* name);
    Student(int id, const char* fullname, const char* address, double gpa);
    Student(const Student& other);
    Student(string s);
    ~Student();

    Student& operator=(const Student& other);

    string toString() const;
    Student clone() const;
    void display() const;
};
