#include "../inc/Fixed.hpp"
#include <bitset>

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
	: fixed_v(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nb)
	: fixed_v(nb.fixed_v)
{
	std::cout << "overloaded constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "copy operator called" << std::endl;
	if (this != &other)
		fixed_v = other.fixed_v;
	// std::cout << fixed_v << "---" << other.fixed_v << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int int_to_fp)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_v = int_to_fp << fractional_bits;
}

Fixed::Fixed(const float float_to_fp)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_v = (float_to_fp * (1 << fractional_bits) + 0.5);
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_v);
}

void Fixed::setRawBits(int const raw)
{
	fixed_v = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixed_v) / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return fixed_v >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
