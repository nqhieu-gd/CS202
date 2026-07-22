#pragma once
#include <iostream>

class A {
protected:
    char* m_s;
public:
    A();
    A(const char* s);
    A(const A& other);
    virtual ~A();

    virtual void prepare() const;
    void display() const;

    A& operator=(const A& other);

    friend std::ostream& operator<<(std::ostream& os, const A& a);
    friend std::istream& operator>>(std::istream& is, A& a);
};

class B : public A {
public:
    B(const char* s);
    B(const B& other);
    ~B();

    void prepare() const override;

    B& operator=(const B& other);

    friend std::ostream& operator<<(std::ostream& os, const B& b);
    friend std::istream& operator>>(std::istream& is, B& b);
};

void foo(A a, const A& b);
