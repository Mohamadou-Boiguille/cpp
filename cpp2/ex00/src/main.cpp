#include "../inc/Fixed.hpp"

int main() {
    Fixed a;
    a.setRawBits(42);
    Fixed b(a);
    b.setRawBits(21);
    Fixed c;

    c = b;


    std::cout << "a = " << a.getRawBits() << std::endl;
    std::cout << "b = " << b.getRawBits() << std::endl;
    std::cout << "c = " << c.getRawBits() << std::endl;

    return 0;
}

