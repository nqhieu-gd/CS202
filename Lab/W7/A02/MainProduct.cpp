#include <vector>
#include <stdexcept>
#include <iostream>

#include "Product.h"

void MP::changeType() {
    int n = 1;
    for (auto c : type) {
        std::cout << n++ << ". " << c << '\n';
    }
    std::cout << "-------------------------------------------------------------------------------\n";
    std::cout << "Choose type of product: ";
    std::cin >> n;
    if (n < 1 || n > type.size()) throw std::out_of_range("No such type exists!");
    curType = n - 1;
}

void MP::setNum(int i) {
    if (i < 0) throw std::domain_error("Number of products cannot be negative!");
    num -= numPerType[curType];
    numPerType[curType] = i;
    num += i;
}

void MP::takeGift(int idx) {
    if (idx < 0 || idx > GiftList.size()) throw std::out_of_range("No such gift exists!");
    GiftList[idx]->getGift();
}

bool MP::checkCategory(std::string ctgr) const {
    return (category == ctgr);
}

int MP::howMany() const {
    return num;
}

void MP::Addition() {
    numPerType[curType] += 1;
}

void MP::Deduction() {
    if (numPerType[curType] > 0) numPerType[curType] -= 1;
}

void MP::display() const {
    std::cout << "-------------------------------------------------------------------------------\n";
    std::cout << name << '\n';
    std::cout << type[curType]  << '\n';
    std::cout << price[curType] << "VND" << '\n';
    std::cout << "Number currently chosen: " << numPerType[curType] << '\n';
    std::cout << "-------------------------------------------------------------------------------\n";
}