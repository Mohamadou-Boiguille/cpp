#include "../inc/Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
	: fixed_v(0)
{
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nb)
	: fixed_v(nb.fixed_v)
{
	// std::cout << "overloaded constructor called" << std::endl;
}

Fixed::Fixed(const int int_to_fp)
{
	// std::cout << "Int constructor called" << std::endl;
	fixed_v = int_to_fp << fractional_bits;
}

Fixed::Fixed(const float float_to_fp)
{
	// std::cout << "Float constructor called" << std::endl;
	fixed_v = static_cast<int>(float_to_fp * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed Fixed::operator=(const Fixed &other)
{
	// std::cout << "copy operator called" << std::endl;
	if (this != &other)
		fixed_v = other.fixed_v;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fixed_v);
}

void Fixed::setRawBits(int const raw)
{
	fixed_v = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_v) / (1 << fractional_bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(roundf((float)this->fixed_v / (1 << this->fractional_bits))));
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(fixed_v + other.fixed_v));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(fixed_v - other.fixed_v));
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(other.toFloat() * this->toFloat()));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(fixed_v / other.fixed_v));
}

bool Fixed::operator>(const Fixed &other)
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other)
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other)
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other)
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other)
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other)
{
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator++()
{
	fixed_v += 1;
	return (*this);
}
