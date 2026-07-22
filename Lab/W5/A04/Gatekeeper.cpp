#include "Gatekeeper.h"
#include <iostream>

bool Merchant::deduct(Prince& p) {
    float cost = req * quantity;
    if (p.money >= cost) {
        p.money -= cost;
        return true;
    }
    return false;
}
void Merchant::show() {
    std::cout << "Business Gate (" << req << 'x' << quantity << ")\n";
}

bool Sage::deduct(Prince& p) {
    return p.IQ >= req;
}
void Sage::show() {
    std::cout << "Academic Gate (" << req << ")\n";
}

bool Warrior::deduct(Prince& p) {
    bool con = (p.strength >= req);
    if (con) p.strength -= debuff;
    return con;
}
void Warrior::show() {
    std::cout << "Power Gate (" << req << ")\n";
}
