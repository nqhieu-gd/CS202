#pragma once
#include "CartItem.h"

class FreeGift : public CartItem {
public:
    FreeGift();
    FreeGift(const std::string& name, const std::string& variant, int qty);
    FreeGift(const FreeGift& other);
    FreeGift(const std::string& name, int qty);
    explicit FreeGift(const std::string& data);
    ~FreeGift();

    void displayInfo() const override;
};
