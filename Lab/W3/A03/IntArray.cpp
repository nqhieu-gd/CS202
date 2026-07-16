#include "IntArray.h"

IntArray::IntArray() : data(nullptr), size(0) {}

IntArray::IntArray(int n) : data(nullptr), size(n) {
    if (n > 0)
        data = new int[n]();
}

IntArray::IntArray(const int* arr, int n) : data(nullptr), size(n) {
    if (n > 0) {
        data = new int[n];
        for (int i = 0; i < n; i++)
            data[i] = arr[i];
    }
}

IntArray::IntArray(const IntArray& other) : data(nullptr), size(other.size) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
}

IntArray::~IntArray() {
    delete[] data;
    data = nullptr;
}

IntArray& IntArray::operator=(const IntArray& other) {
    if (this != &other) {
        int* newData = nullptr;
        if (other.size > 0) {
            newData = new int[other.size];
            for (int i = 0; i < other.size; i++)
                newData[i] = other.data[i];
        }
        delete[] data;
        data = newData;
        size = other.size;
    }
    return *this;
}

int& IntArray::operator[](int index) {
    return data[index];
}

int IntArray::operator[](int index) const {
    return data[index];
}

IntArray::operator int() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const IntArray& arr) {
    os << '[';
    for (int i = 0; i < arr.size; i++) {
        if (i > 0) os << ", ";
        os << arr.data[i];
    }
    os << ']';
    return os;
}

std::istream& operator>>(std::istream& is, IntArray& arr) {
    for (int i = 0; i < arr.size; i++)
        is >> arr.data[i];
    return is;
}
