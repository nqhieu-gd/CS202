#include "Course.h"

#include <string>
#include <iostream>

using std::string;

void Course::push(mt* cpn) {
    list.push_back(cpn);
}

void Course::gen(std::ifstream& is) {
    int type;
    int drt;
    int NOW;
    string temp;
    string str = "";
    while (is >> type && is >> drt && is >> NOW) {
        for (int i = 0; i < NOW; i++) {
            is >> temp;
            str += temp;
            if (i != NOW - 1) str += ' ';
        }
        mt* tempC = nullptr;
        if (type == 1) tempC = new video(str, drt);
        else if (type == 2) tempC = new quiz(str, drt);
        else if (type == 3) {
            module* subMd = new module(str);
            fin(is, *subMd, drt);
            tempC = subMd;
        }
        push(tempC);
        str = "";
    }
}

void Course::display() {
    for (auto* c : list) if (c != nullptr) c->display(0);
}

Course::~Course() {
    for (auto* c : list) if (c != nullptr) delete c;
}