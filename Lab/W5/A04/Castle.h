#pragma once
#include <vector>

class Gatekeeper;

struct Prince{
    float money;
    float IQ;
    float strength;

    Prince(): money(0), IQ(0), strength(0) {}
    Prince(float m, float i, float s): money(m), IQ(i), strength(s) {}
    Prince(const Prince& p) {
        money = p.money;
        IQ = p.IQ;
        strength = p.strength;
    }

    void display();
};

class Gatekeeper {
protected:
    float req;
public:
    Gatekeeper(): req(0) {};
    Gatekeeper(float requirement): req(requirement) {};
    virtual ~Gatekeeper() = default;

    virtual bool deduct(Prince& p) = 0;
    virtual void show() = 0;
};

class Castle {
    std::vector<Gatekeeper*> g;
    Prince p;
    int currentGatekeeper;
public:
    Castle(): currentGatekeeper(0) {};
    Castle(std::vector<Gatekeeper*>& gatekeepers, Prince prince): g(gatekeepers), p(prince), currentGatekeeper(0) {};
    ~Castle();

    void add(Gatekeeper* gk);
    void successOrNot();
};