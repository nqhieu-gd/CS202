#pragma once

#include <vector>
#include <fstream>
#include <string>

class MP;

class Gift;

/*-------------------------------------------------------------------------------------------------------------------------*/

class S {
private:
    std::string name;
    std::vector<const MP*> ShopList;
    std::vector<const Gift*> GiftList;
    std::string theme;

    int sum;
public:
    S(): name(""), theme(""), sum(0.0) {}
    S(std::string name, std::vector<const MP*>& ShopList, std::vector<const Gift*>& GiftList): name(name), ShopList(ShopList), GiftList(GiftList), sum(0.0) {}
    S(const S &other);

    ~S();

    void show() const;
    void select(int idx);
    void remove(int idx);
    void increase(int idx);
    void decrease(int idx);
    void set(const MP* item);
    int totalSum() const;
    void addIn(const MP* item);
    bool checkTheme(std::string thm) const;
};