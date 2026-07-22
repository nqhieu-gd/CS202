#include "a.h"
#include <cstring>

std::ostream& operator<<(std::ostream& os, const myStr& str) {
    if (str.data != nullptr) {
        os << str.data;
    }
    return os;
}