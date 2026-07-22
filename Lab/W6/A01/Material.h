#pragma once

#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

class mt {
protected:
    string title;
    int dur;
public:
    virtual void display(int i) = 0;
    int durHour() const;
    int getDur() const;

    mt();
    mt(string title, int dur);
    virtual ~mt() = default;
};

class video : public mt {
private:
public:
    void display(int i) override;

    video(string title, int dur);
};

class quiz : public mt {
private:
    int num;
public:
    void display(int i) override;

    quiz(string title, int num);
};

class module : public mt {
private:
    vector<mt*> cts;
public:
    void add(mt* ct);
    void display(int i) override;

    module(string title);
    ~module();
};

void fin(std::istream& is, module& mdl, int size);