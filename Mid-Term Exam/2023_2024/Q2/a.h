#include <string>
#include <iostream>

class myStr {
private:
    char* data = nullptr;
    int size;
    
public:
    myStr(const char* str);
    myStr(const myStr& other);
    ~myStr();

    bool operator==(const myStr& other) const;
    bool operator!=(const myStr& other) const;
    bool operator<(const myStr& other) const;
    bool operator>(const myStr& other) const;
    myStr operator+(const myStr& other) const;
    myStr& operator=(const myStr& other);
    char& operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const myStr& str);
};

std::ostream& operator<<(std::ostream& os, const myStr& str);