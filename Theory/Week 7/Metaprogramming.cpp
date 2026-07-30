#include <iostream>

template<int N>
class sthsth {
public:
    static const long long int val = sthsth<N-1>::val;
};

template<>
class sthsth<0> {
public:
    static const long long int val = 1;
};

int main() {
    std::cout << sthsth<900>::val << std::endl;
    return 0;
}