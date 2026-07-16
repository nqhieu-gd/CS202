#pragma once
#include <iostream>

class IntArray {
private:
    int* data;
    int size;

public:
    IntArray();
    IntArray(int n);
    IntArray(const int* arr, int n);
    IntArray(const IntArray& other);
    ~IntArray();

    IntArray& operator=(const IntArray& other);

    int& operator[](int index);
    int operator[](int index) const;

    operator int() const;

    friend std::ostream& operator<<(std::ostream& os, const IntArray& arr);
    friend std::istream& operator>>(std::istream& is, IntArray& arr);
};
