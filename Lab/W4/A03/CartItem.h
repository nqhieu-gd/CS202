#pragma once
#include <iostream>
#include <string>

class CartItem {
protected:
    std::string name;
    std::string variant;
    double unitPrice;
    int quantity;
    bool checked;
public:
    CartItem();
    CartItem(const std::string& name, const std::string& variant, double price, int qty);
    CartItem(const CartItem& other);
    CartItem(const std::string& name, double price);
    explicit CartItem(const std::string& data);
    virtual ~CartItem();

    virtual void displayInfo() const;
    virtual double getTotalPrice() const;

    void setChecked(bool c);
    bool isChecked() const;
    void adjustQuantity(int delta);
    int getQuantity() const;
    std::string getName() const;
};
