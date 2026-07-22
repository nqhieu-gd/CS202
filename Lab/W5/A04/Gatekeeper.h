#pragma once
#include "Castle.h"

class Merchant : public Gatekeeper {
private:
    int quantity;
public:
    Merchant(float unitPrice, int qty): Gatekeeper(unitPrice), quantity(qty) {};
    ~Merchant() {};

    bool deduct(Prince& p) override;
    void show() override;
};

class Sage : public Gatekeeper {
public:
    Sage(float requirement): Gatekeeper(requirement) {};
    ~Sage() {};

    bool deduct(Prince& p) override;
    void show() override;
};

class Warrior : public Gatekeeper {
private:
    int debuff;
public:
    Warrior(float requirement, int penalty): Gatekeeper(requirement), debuff(penalty) {};
    ~Warrior() {};

    bool deduct(Prince& p) override;
    void show() override;
};
