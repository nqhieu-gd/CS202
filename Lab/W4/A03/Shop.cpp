#include "Shop.h"

Shop::Shop(const std::string& nm) : name(nm), checked(true) {}

Shop::~Shop() {
    for (CartItem* item : items) {
        delete item;
    }
}

void Shop::addItem(CartItem* item) {
    items.push_back(item);
}

void Shop::displayInfo() const {
    std::cout << "\n<< " << name << " >>";
    if (!checked) std::cout << " (unchecked)";
    std::cout << std::endl;
    for (const CartItem* item : items) {
        item->displayInfo();
    }
}

double Shop::getTotalPrice() const {
    if (!checked) return 0;
    double total = 0;
    for (const CartItem* item : items) {
        total += item->getTotalPrice();
    }
    return total;
}

std::string Shop::getName() const { return name; }
void Shop::setChecked(bool c) { checked = c; }
bool Shop::isChecked() const { return checked; }
