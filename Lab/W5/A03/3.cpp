#include "3.h"
#include <cstring>

// --- A ---

A::A() : m_s(nullptr) {
    m_s = new char[8];
    std::strcpy(m_s, "default");
}

A::A(const char* s) : m_s(nullptr) {
    if (s) {
        m_s = new char[std::strlen(s) + 1];
        std::strcpy(m_s, s);
    } else {
        m_s = new char[8];
        std::strcpy(m_s, "default");
    }
}

A::A(const A& other) : m_s(nullptr) {
    if (other.m_s) {
        m_s = new char[std::strlen(other.m_s) + 1];
        std::strcpy(m_s, other.m_s);
    }
}

A::~A() {
    delete[] m_s;
}

void A::prepare() const {
    std::cout << "A ";
}

void A::display() const {
    prepare();
    std::cout << m_s << std::endl;
}

A& A::operator=(const A& other) {
    if (this != &other) {
        delete[] m_s;
        m_s = nullptr;
        if (other.m_s) {
            m_s = new char[std::strlen(other.m_s) + 1];
            std::strcpy(m_s, other.m_s);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const A& a) {
    os << "A(" << (a.m_s ? a.m_s : "null") << ")";
    return os;
}

std::istream& operator>>(std::istream& is, A& a) {
    char buf[1024];
    is >> buf;
    delete[] a.m_s;
    a.m_s = new char[std::strlen(buf) + 1];
    std::strcpy(a.m_s, buf);
    return is;
}

// --- B ---

B::B(const char* s) : A(s) {}

B::B(const B& other) : A(other) {}

B::~B() {}

void B::prepare() const {
    std::cout << "B ";
}

B& B::operator=(const B& other) {
    if (this != &other) {
        A::operator=(other);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const B& b) {
    os << "B(" << (b.m_s ? b.m_s : "null") << ")";
    return os;
}

std::istream& operator>>(std::istream& is, B& b) {
    char buf[1024];
    is >> buf;
    delete[] b.m_s;
    b.m_s = new char[std::strlen(buf) + 1];
    std::strcpy(b.m_s, buf);
    return is;
}

void foo(A a, const A& b) {
    a.display();
    b.display();
}
