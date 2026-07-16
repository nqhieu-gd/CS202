#include "CartItem.h"
#include <sstream>

CartItem::CartItem() : unitPrice(0), quantity(1), checked(true) {}

CartItem::CartItem(const std::string& nm, const std::string& var, double price, int qty)
    : name(nm), variant(var), unitPrice(price), quantity(qty), checked(true) {}

CartItem::CartItem(const CartItem& other)
    : name(other.name), variant(other.variant), unitPrice(other.unitPrice),
      quantity(other.quantity), checked(other.checked) {}

CartItem::CartItem(const std::string& nm, double price)
    : name(nm), variant(""), unitPrice(price), quantity(1), checked(true) {}

CartItem::CartItem(const std::string& data) {
    size_t p1 = data.find(" || ");
    size_t p2 = data.find(" || ", p1 + 4);
    size_t p3 = data.find(" || ", p2 + 4);
    size_t p4 = data.find(" || ", p3 + 4);
    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos || p4 == std::string::npos) {
        std::cerr << "Error: invalid CartItem string: " << data << std::endl;
        return;
    }
    name = data.substr(0, p1);
    variant = data.substr(p1 + 4, p2 - p1 - 4);
    unitPrice = std::stod(data.substr(p2 + 4, p3 - p2 - 4));
    quantity = std::stoi(data.substr(p3 + 4, p4 - p3 - 4));
    checked = (std::stoi(data.substr(p4 + 4)) != 0);
}

CartItem::~CartItem() {}

void CartItem::displayInfo() const {
    std::cout << name;
    if (!variant.empty()) std::cout << " [" << variant << "]";
    std::cout << " x" << quantity;
    std::cout << " @ " << unitPrice << " VND";
    if (!checked) std::cout << " (unchecked)";
    std::cout << std::endl;
}

double CartItem::getTotalPrice() const {
    return checked ? unitPrice * quantity : 0;
}

void CartItem::setChecked(bool c) { checked = c; }
bool CartItem::isChecked() const { return checked; }

void CartItem::adjustQuantity(int delta) {
    quantity += delta;
    if (quantity < 1) quantity = 1;
}

int CartItem::getQuantity() const { return quantity; }
std::string CartItem::getName() const { return name; }
