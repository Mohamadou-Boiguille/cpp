#include "../inc/Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
	: fixed_v(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nb)
	: fixed_v(nb.fixed_v)
{
	std::cout << "copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "copy assignement operator called" << std::endl;
	if (this != &other)
		this->fixed_v = other.fixed_v;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_v);
}

void Fixed::setRawBits(int const raw)
{
	const int	mask = (1 << fractional_bits) - 1;
	fixed_v = raw & mask;
	std::cout << "setRawBits member function called" << std::endl;
}
