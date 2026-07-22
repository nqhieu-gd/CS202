#include "a.h"
#include <cstring>

myStr& myStr::operator=(const myStr& other) {
    if(this != &other) {
        delete[] data;
        if (other.data == nullptr) {
            data = nullptr;
            size = 0;
            return *this;
        }
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }
    return *this;
}