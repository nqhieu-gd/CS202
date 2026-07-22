#include "Castle.h"
#include <iostream>

Castle::~Castle() {
    for (int i = 0; i < g.size(); i++) delete g[i];
}

void Prince::display() {
    std::cout << "Remaining money: " << money << '\n';
    std::cout << "IQ level: " << IQ << '\n';
    std::cout << "Strength left: " << strength << '\n';
}

void Castle::add(Gatekeeper* gk) {
    g.push_back(gk);
}

void Castle::successOrNot() {
    Prince sub = p;
    int id = 0;
    for (; id < g.size(); id++) {
        if (!(g[id]->deduct(sub))) break;
    }
    if (id >= g.size()) {
        std::cout << "Success!" << std::endl;
        sub.display();
    }
    else {
        std::cout << g.size() - id << " gates left" << std::endl;
        while (id < g.size()) {
            std::cout << "Gate number " << id + 1 <<": ";
            g[id++]->show();
        }
    }
}