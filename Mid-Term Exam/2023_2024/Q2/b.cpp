#include "a.h"
#include <cstring>

myStr myStr::operator+(const myStr& other) const {
    if (other.data == nullptr) {
        return *this;
    }
    if (this->data == nullptr) {
        return other;
    }
    int newSize = size + other.size + 1;
    char* newData = new char[newSize];
    std::strcpy(newData, data);
    std::strcat(newData, other.data);
    myStr res(newData);
    delete[] data;
    return res;
}