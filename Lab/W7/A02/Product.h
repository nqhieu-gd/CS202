#pragma once

#include <string>
#include <vector>

class S;

class Con {
public:
    Con* copyP() const;
    bool check() const;
};

class GoodsCon;

/*-------------------------------------------------------------------------------------------------------------------------*/

class P {
protected:
    std::string name;
    std::vector<std::string> type;
    int num;
public:
    P(): name(""), num(0) {}
    P(std::string name, std::vector<std::string>& type): name(name), type(type), num(0) {}
    P(const P &other): name(other.name), type(other.type), num(0) {}

    virtual ~P() = default;

    virtual void Addition() = 0;
    virtual void Deduction() = 0;
    virtual void display() const = 0;
};

class Gift : public P {
private:
    Con* C;
    void Addition() override;
    void Deduction() override;
public:
    Gift();
    Gift(std::string name, std::vector<std::string>& type, Con* C): P(name, type), C(C) {}
    Gift(const Gift &other): P(other) {
        C = other.C->copyP();
    }

    ~Gift();

    void getGift();
    void validate();

    void display() const override;
};

class MP : public P {
private:
    std::vector<int> numPerType;
    std::vector<int> price;
    int curType;
    std::string category;
    std::vector<Gift*> GiftList;
public:
    MP(): curType(0), category("") {}
    MP(std::string name, std::vector<std::string>& type, std::vector<int>& price, std::vector<Gift*>& GiftList): P(name, type), price(price), GiftList(GiftList), curType(0) {
        numPerType = std::vector(type.size(), 0);
    }
    MP(const MP &other): P(other), price(other.price), curType(0), category(category) {
        numPerType = std::vector(other.numPerType.size(), 0);
        for (int i = 0; i < other.GiftList.size(); i++) {
            Gift* sub = new Gift(*(other.GiftList[i]));
            this->GiftList.push_back(sub);
        }
    }

    ~MP();

    const S* originS;
    
    void changeType();
    void setNum(int i);
    void takeGift(int idx);
    bool checkCategory(std::string ctgr) const;
    int howMany() const;

    void Addition() override;
    void Deduction() override;
    void display() const override;
};