#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CartItem.h"

class Shop {
private:
    std::string name;
    std::vector<CartItem*> items;
    bool checked;
public:
    Shop(const std::string& name);
    ~Shop();
    Shop(const Shop&) = delete;
    Shop& operator=(const Shop&) = delete;

    void addItem(CartItem* item);
    void displayInfo() const;
    double getTotalPrice() const;
    std::string getName() const;
    void setChecked(bool c);
    bool isChecked() const;
};
