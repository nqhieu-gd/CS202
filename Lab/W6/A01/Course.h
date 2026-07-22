#pragma once

#include "Material.h"

#include <fstream>
#include <vector>

using std::vector;

class Course {
private:
    vector<mt*> list;
public:
    void push(mt* cpn);
    void gen(std::ifstream& is);
    void display();

    ~Course();
};