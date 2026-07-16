#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"

class ShoppingCart {
private:
    std::vector<Shop*> shops;
public:
    ShoppingCart();
    ~ShoppingCart();
    ShoppingCart(const ShoppingCart&) = delete;
    ShoppingCart& operator=(const ShoppingCart&) = delete;

    void addShop(Shop* shop);
    void displayCart() const;
    double getTotalPrice() const;
    int getCheckedItemCount() const;
    void checkout() const;
};
