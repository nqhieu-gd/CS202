#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {}

ShoppingCart::~ShoppingCart() {
    for (Shop* shop : shops) {
        delete shop;
    }
}

void ShoppingCart::addShop(Shop* shop) {
    shops.push_back(shop);
}

void ShoppingCart::displayCart() const {
    std::cout << "=== SHOPPING CART ===" << std::endl;
    for (const Shop* shop : shops) {
        shop->displayInfo();
    }
    std::cout << "\nTotal: " << getTotalPrice() << " VND";
    std::cout << " (" << getCheckedItemCount() << " items)" << std::endl;
}

double ShoppingCart::getTotalPrice() const {
    double total = 0;
    for (const Shop* shop : shops) {
        total += shop->getTotalPrice();
    }
    return total;
}

int ShoppingCart::getCheckedItemCount() const {
    int count = 0;
    for (const Shop* shop : shops) {
        count += 1;
    }
    return count;
}

void ShoppingCart::checkout() const {
    std::cout << "\nCheck Out (" << getCheckedItemCount() << ")" << std::endl;
    std::cout << "Total: " << getTotalPrice() << " VND" << std::endl;
}
