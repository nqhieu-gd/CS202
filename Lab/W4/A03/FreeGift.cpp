#include "FreeGift.h"
#include <sstream>

FreeGift::FreeGift() : CartItem() { unitPrice = 0; }

FreeGift::FreeGift(const std::string& nm, const std::string& var, int qty)
    : CartItem(nm, var, 0, qty) {}

FreeGift::FreeGift(const FreeGift& other) : CartItem(other) {}

FreeGift::FreeGift(const std::string& nm, int qty)
    : CartItem(nm, 0) { quantity = qty; unitPrice = 0; }

FreeGift::FreeGift(const std::string& data) : CartItem() {
    size_t p1 = data.find(" || ");
    size_t p2 = data.find(" || ", p1 + 4);
    size_t p3 = data.find(" || ", p2 + 4);
    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos) {
        std::cerr << "Error: invalid FreeGift string: " << data << std::endl;
        return;
    }
    name = data.substr(0, p1);
    variant = data.substr(p1 + 4, p2 - p1 - 4);
    quantity = std::stoi(data.substr(p2 + 4, p3 - p2 - 4));
    checked = (std::stoi(data.substr(p3 + 4)) != 0);
    unitPrice = 0;
}

FreeGift::~FreeGift() {}

void FreeGift::displayInfo() const {
    std::cout << "[Gift] " << name;
    if (!variant.empty()) std::cout << " [" << variant << "]";
    std::cout << " x" << quantity << " FREE";
    if (!checked) std::cout << " (unchecked)";
    std::cout << std::endl;
}
