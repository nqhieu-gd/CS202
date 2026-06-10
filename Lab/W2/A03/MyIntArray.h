#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class MyIntArray {
private:
    int* a;
    int n;

public:
    MyIntArray();
    MyIntArray(int n);
    MyIntArray(int n, int* arr);
    MyIntArray(const MyIntArray& other);
    MyIntArray(string s);

    ~MyIntArray();

    MyIntArray& operator=(const MyIntArray& other);

    string toString() const;
    MyIntArray clone() const;
    int sum() const;
    int max() const;
    int min() const;
    void sortAsc();
    void display() const;
};
