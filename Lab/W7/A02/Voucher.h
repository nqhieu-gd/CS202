#pragma once

#include <string>
#include <stdexcept>

class MP;

class S;

/*-------------------------------------------------------------------------------------------------------------------------*/

class V {
private:
    std::string name;
    int type;
    int percentage;
    int maxDiscount;
    bool isActive = false;
public:
    V(): name(""), type(-1) {}
    V(std::string name, int type, int percent, int maxD): name(name), type(type), percentage(percent), maxDiscount(maxD) {
        if (type < 0 || percent > 100 || percent < 0) throw std::invalid_argument("Invalid type");
    }

    bool isValid(const S& shop) const;
};