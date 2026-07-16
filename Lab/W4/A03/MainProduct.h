#pragma once
#include "CartItem.h"

class MainProduct : public CartItem {
private:
    double originalPrice;
public:
    MainProduct();
    MainProduct(const std::string& name, const std::string& variant, double price, int qty, double origPrice);
    MainProduct(const MainProduct& other);
    MainProduct(const std::string& name, double price);
    explicit MainProduct(const std::string& data);
    ~MainProduct();

    void displayInfo() const override;
};
