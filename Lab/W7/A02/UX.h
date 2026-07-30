#pragma once

#include <vector>
#include <fstream>

class S;

class P;

class MP;

class V;

/*-------------------------------------------------------------------------------------------------------------------------*/

class UX {
private:
    std::vector<const S*> shops;
public:
    UX();
    UX(const UX& other);
    UX(std::ifstream& is);
    ~UX();

    void add(const MP* prod);
    void remove(const S* shop);
    void increaseCount(const MP* prod);
    void decreaseCount(const MP* prod);
    void setAmount(const MP* prod);
    void appVoucher(V* Voucher);
    int totalPay() const;
    void displayUX() const;

    void saveF(std::ofstream& os);
};