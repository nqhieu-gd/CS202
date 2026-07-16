#include "FileStructure.h"
#include <iostream>

char* dateCopy(char date[10]) {
    char copy[10];
    for (int i = 0; i < 10; i++) {
        copy[i] = date[i];
    }
    return copy;
}

systemElement::~systemElement() {
    delete[] date;
}

systemFile::systemFile(std::string name, char date[10], float size) {
    this->name = name;
    this->date = dateCopy(date);
    this->size = size;
}