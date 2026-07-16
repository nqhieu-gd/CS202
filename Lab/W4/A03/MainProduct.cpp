#include "MainProduct.h"
#include <sstream>

MainProduct::MainProduct() : CartItem(), originalPrice(0) {}

MainProduct::MainProduct(const std::string& nm, const std::string& var, double price, int qty, double origPrice)
    : CartItem(nm, var, price, qty), originalPrice(origPrice) {}

MainProduct::MainProduct(const MainProduct& other)
    : CartItem(other), originalPrice(other.originalPrice) {}

MainProduct::MainProduct(const std::string& nm, double price)
    : CartItem(nm, price), originalPrice(0) {}

MainProduct::MainProduct(const std::string& data) : CartItem() {
    size_t p1 = data.find(" || ");
    size_t p2 = data.find(" || ", p1 + 4);
    size_t p3 = data.find(" || ", p2 + 4);
    size_t p4 = data.find(" || ", p3 + 4);
    size_t p5 = data.find(" || ", p4 + 4);
    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos
        || p4 == std::string::npos || p5 == std::string::npos) {
        std::cerr << "Error: invalid MainProduct string: " << data << std::endl;
        return;
    }
    name = data.substr(0, p1);
    variant = data.substr(p1 + 4, p2 - p1 - 4);
    unitPrice = std::stod(data.substr(p2 + 4, p3 - p2 - 4));
    quantity = std::stoi(data.substr(p3 + 4, p4 - p3 - 4));
    checked = (std::stoi(data.substr(p4 + 4, p5 - p4 - 4)) != 0);
    originalPrice = std::stod(data.substr(p5 + 4));
}

MainProduct::~MainProduct() {}

void MainProduct::displayInfo() const {
    std::cout << "[Product] " << name;
    if (!variant.empty()) std::cout << " [" << variant << "]";
    std::cout << " x" << quantity;
    std::cout << " @ " << unitPrice << " VND";
    if (originalPrice > unitPrice)
        std::cout << " (was " << originalPrice << " VND)";
    if (!checked) std::cout << " (unchecked)";
    std::cout << std::endl;
}
