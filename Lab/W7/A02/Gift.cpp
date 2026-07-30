#include <iostream>

#include "Product.h"

void Gift::Addition() {
    num++;
}

void Gift::Deduction() {
    if (num > 0) num--;
}

void Gift::getGift() {
    if (C->check()) Addition;
}

void Gift::validate() {
    if (!C->check()) Deduction();
}

void Gift::display() const {
    std::cout << "-------------------------------------------------------------------------------\n";
    std::cout << name << '\n';
    std::cout << "Number currently chosen: " << num << '\n';
    std::cout << "-------------------------------------------------------------------------------\n";
}