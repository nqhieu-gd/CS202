#pragma once

#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

class mt {
protected:
    string title;
public:
    virtual void display(int i) = 0;
    int durHour() const;
    virtual int getDur() const = 0;

    mt();
    mt(string title);
    virtual ~mt() = default;
};

class video : public mt {
private:
    int dur;
public:
    void display(int i) override;
    int getDur() const override;

    video(string title, int dur);
};

class quiz : public mt {
private:
    int num;
public:
    void display(int i) override;
    int getDur() const override;

    quiz(string title, int num);
};

class module : public mt {
private:
    vector<mt*> cts;
public:
    void add(mt* ct);
    void display(int i) override;
    int getDur() const override;

    module(string title);
    ~module();
};

void fin(std::istream& is, module& mdl, int size);
