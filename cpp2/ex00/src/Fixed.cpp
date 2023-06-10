#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default constructor called" << std::endl;
	fixed_v = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	//destructor
}

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
	return (fixed_v);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
	fixed_v = raw;
}
