#include <vector>

#include "Condition.h"

bool ShopCon::check() const {
    for (int i = 0; i < req.size(); i++) {
        if (num[i] > req[i]->howMany()) return false;
    }
    return (src->totalSum() >= minPrice);
}

Con* ShopCon::copyP() const {
    Con* sub = new ShopCon(*this);
    return sub;
}

bool GoodsCon::check() const {
    return (src->howMany() >= minNum);
}

Con* GoodsCon::copyP() const {
    Con* sub = new GoodsCon(*this);
    return sub;
}