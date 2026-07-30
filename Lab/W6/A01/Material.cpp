#include "Material.h"

#include <iostream>

using std::cout;

int mt::durHour() const {
    return getDur() / 60;
}

mt::mt(): title("") {}

mt::mt(string title): title(title) {}

int video::getDur() const {
    return dur;
}

void video::display(int i) {
    cout << "[Video] " << title << " (" << durHour() << "h " << getDur() % 60 << "m)\n";
}

video::video(string title, int dur): mt(title), dur(dur) {}

int quiz::getDur() const {
    return num * 2;
}

void quiz::display(int i) {
    cout << "[Quiz] " << title << " (" << num << " questions, " << durHour() << "h " << getDur() % 60 << "m)\n";
}

quiz::quiz(string title, int num): mt(title), num(num) {}

void module::add(mt* ct) {
    cts.push_back(ct);
}

int module::getDur() const {
    int total = 0;
    for (auto* c : cts) {
        if (c != nullptr) total += c->getDur();
    }
    return total;
}

void module::display(int i) {
    int d = getDur();
    cout << "[Module] " << title << " (" << durHour() << "h " << d % 60 << "m)\n";
    for (auto* c : cts) {
        for (int j = 0; j <= i; j++) std::cout << "   ";
        c->display(i + 1);
    }
}

module::module(string title): mt(title) {}

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
