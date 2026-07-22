#include "Material.h"

#include <iostream>

using std::cout;

int mt::durHour() const {
    return dur/60;
}

int mt::getDur() const {
    return dur;
}

mt::mt(): title(""), dur(0) {}

mt::mt(string title, int dur): title(title), dur(dur) {}

void video::display(int i) {
    cout << "[Video] " << title << " (" << durHour() << "h " << dur%60 << "m)\n";
}

video::video(string title, int dur): mt(title, dur) {}

void quiz::display(int i) {
    cout << "[Quiz] " << title << " (" << num << " questions, " << durHour() << "h " << dur%60 << "m)\n";
}

quiz::quiz(string title, int num): mt(title, num*2), num(num) {}

void module::add(mt* ct) {
    cts.push_back(ct);
    dur += ct->getDur();
}

void module::display(int i) {
    cout << "[Module] " << title << " (" << durHour() << "h " << dur%60 << "m)\n";
    for (auto* c : cts) {
        for (int j = 0; j <= i; j++) std::cout << "   ";
        c->display(i + 1);
    }
}

module::module(string title): mt(title, 0) {}

module::~module() {
    for (auto* c : cts) if (c != nullptr) delete c;
}

void fin(std::istream& is, module& mdl, int size) {
    int type;
    int drt;
    int NOW;
    string temp;
    string str = "";
    for (int k = 0; k < size; k++) {
        if (is >> type && is >> drt && is >> NOW) {
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
            mdl.add(tempC);
            str = "";
        }
    }
}