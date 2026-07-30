#pragma once

#include <vector>

class MP {
public:
    int howMany() const;
};

class S {
public:
    int totalSum() const;
};

/*-------------------------------------------------------------------------------------------------------------------------*/

class Con {
public:
    Con();

    virtual ~Con() = default;

    virtual bool check() const = 0;
    virtual Con* copyP() const = 0;
};

class ShopCon : public Con {
private:
    std::vector<const MP*> req;
    std::vector<const int> num;
    const S* src;
    int minPrice;
public:
    ShopCon(): minPrice(0), src(nullptr) {}
    ShopCon(std::vector<const MP*>& r, int price, std::vector<const int>& num, S* src): req(r), minPrice(price), num(num), src(src) {}
    ShopCon(const ShopCon& other): req(other.req), minPrice(other.minPrice), num(other.num), src(other.src) {}

    ~ShopCon();

    bool check() const override;
    Con* copyP() const override;
};

class GoodsCon : public Con {
private:
    const MP* src;
    int minNum;
public:
    GoodsCon(): src(nullptr), minNum(0) {}
    GoodsCon(MP* src, int num): src(src), minNum(num) {}
    GoodsCon(const GoodsCon& other): src(other.src), minNum(other.minNum) {}

    ~GoodsCon();

    bool check() const override;
    Con* copyP() const override;
};