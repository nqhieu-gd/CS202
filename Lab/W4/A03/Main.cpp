#include "ShoppingCart.h"
#include "MainProduct.h"
#include "FreeGift.h"

int main() {
    MainProduct* helmet = new MainProduct("Bicycle Helmet", "Black & White, Size M", 572368, 1, 479000);
    FreeGift* sleeves = new FreeGift("Cycling Arm Sleeves", "1 Pair, Black", 1);
    MainProduct* gloves = new MainProduct("Cycling Gloves", "S099 Blue, Size XXL", 81632, 1, 0);

    Shop* shop1 = new Shop("ROCKBROS Global Store");
    shop1->addItem(helmet);
    shop1->addItem(sleeves);
    shop1->addItem(gloves);

    ShoppingCart cart;
    cart.addShop(shop1);

    cart.displayCart();
    cart.checkout();

    std::cout << "\n=== String Constructor Test ===" << std::endl;
    MainProduct* p = new MainProduct("Gloves || Black, L || 50000 || 2 || 1 || 0");
    Shop* s = new Shop("Test Shop");
    s->addItem(p);
    s->displayInfo();
    std::cout << "Item total: " << p->getTotalPrice() << " VND" << std::endl;
    delete s;

    return 0;
}
