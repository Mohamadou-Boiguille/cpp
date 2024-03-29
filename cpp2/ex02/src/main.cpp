#include "../inc/Fixed.hpp"

#include <iostream>

// int main( void ) 
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

// https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html

int main()
{
    Fixed a;
    std::cout << "a: " << a << std::endl;
    std::cout << "Attendu : 0" << std::endl;

    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "b: " << b << std::endl;
    std::cout << "Attendu : 10.1016" << std::endl;

    ++a;
    std::cout << "++a: " << a << std::endl;
    std::cout << "Attendu : 0.00390625" << std::endl;

    std::cout << "a: " << a << std::endl;
    std::cout << "Attendu : 0.00390625" << std::endl;

    std::cout << "a++: " << a++ << std::endl;
    std::cout << "Attendu : 0.00390625" << std::endl;

    std::cout << "a: " << a << std::endl;
    std::cout << "Attendu : 0.0078125" << std::endl;

    Fixed c(2.5f);
    std::cout << "c: " << c << std::endl;
    std::cout << "Attendu : 2.5" << std::endl;

    Fixed d(1.2f);
    std::cout << "d: " << d << std::endl;
    std::cout << "Attendu : 1.2" << std::endl;

    Fixed sum = c + d;
    std::cout << "c + d: " << sum << std::endl;
    std::cout << "Attendu : 3.7" << std::endl;

    Fixed diff = c - d;
    std::cout << "c - d: " << diff << std::endl;
    std::cout << "Attendu : 1.3" << std::endl;

    Fixed prod = c * d;
    std::cout << "c * d: " << prod << std::endl;
    std::cout << "Attendu : 3" << std::endl;

    Fixed div = c / d;
    std::cout << "c / d: " << div << std::endl;
    std::cout << "Attendu : 2.08333" << std::endl;

    bool greater = c > d;
    std::cout << "c > d: " << std::boolalpha << greater << std::endl;
    std::cout << "Attendu : true" << std::endl;

    bool less = c < d;
    std::cout << "c < d: " << std::boolalpha << less << std::endl;
    std::cout << "Attendu : false" << std::endl;

    bool equals = c == d;
    std::cout << "c == d: " << std::boolalpha << equals << std::endl;
    std::cout << "Attendu : false" << std::endl;

    bool notEquals = c != d;
    std::cout << "c != d: " << std::boolalpha << notEquals << std::endl;
    std::cout << "Attendu : true" << std::endl;

    Fixed minResult = Fixed::min(c, d);
    std::cout << "min(c, d): " << minResult << std::endl;
    return 0;
}

