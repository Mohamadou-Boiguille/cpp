#include "../inc/ScalarConverter.hpp"
#include <iostream>

int main (void) {

    std::string input;
    while (input != "end")
    {
        std::cout << "number ? : ";
        std::cin >> input;
            ScalarConverter conversion(static_cast<std::string>(input));
    }
    return 0;
}
