#include "../inc/Fixed.hpp"
#include <cmath>

const int Fixed::fr_bits = 8;

Fixed::Fixed()
	: fp_val(0)
{
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nb)
	: fp_val(nb.fp_val)
{
	// std::cout << "overloaded constructor called" << std::endl;
}

Fixed::Fixed(const int int_to_fp)
	: fp_val (int_to_fp << fr_bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_to_fp)
    :fp_val ((int)roundf(float_to_fp * (1 << fr_bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "copy operator called" << std::endl;
	if (this != &other)
		fp_val = other.fp_val;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fp_val);
}

void Fixed::setRawBits(int const raw)
{
	fp_val = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fp_val) / (1 << fr_bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(roundf((float)this->fp_val / (1 << this->fr_bits))));
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.getRawBits()));
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
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
	fp_val += 1;
	return (*this);
}
