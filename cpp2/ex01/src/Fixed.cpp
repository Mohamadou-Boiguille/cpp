#include "../inc/Fixed.hpp"
#include <math.h>

const int Fixed::fr_bits = 8;

Fixed::Fixed()
	: fp_val(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nb)
	: fp_val(nb.fp_val)
{
	std::cout << "copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "assignement operator called" << std::endl;
	if (this != &other)
		this->fp_val = other.fp_val;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int int_to_fp)
{
    // convertit un entier en nombre à virgule fixe en décalant
    // les bits de int_to_fp vers la gauche de (fr_bits) positions.
    std::cout << "Int constructor called" << std::endl;
    this->fp_val = int_to_fp << fr_bits;
}

Fixed::Fixed(const float float_to_fp)
{
    // convertit un float en nombre à virgule fixe. 
    // Il multiplie float_to_fp par (1 << fr_bits) pour effectuer
    // une multiplication par une puissance de 2, puis ajoute 0,5 
    // pour arrondir la valeur correctement.
    std::cout << "Float constructor called" << std::endl;
    this->fp_val = (float_to_fp * (1 << fr_bits) + 0.5);
}

int Fixed::getRawBits(void)
{
    // retourne la valeur brute de fp_val.
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_val);
}

void Fixed::setRawBits(int const raw)
{
    // définit la valeur brute de fp_val avec la valeur raw
	this->fp_val = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
    // Pour effectuer cette conversion, la fonction divise simplement la valeur de 
    // fp_val par 1 << fr_bits. 1 << fr_bits correspond à une 
    // puissance de 2 (2^fr_bits). 
    // Cela revient à décaler les bits de fp_val vers la droite de 
    // fr_bits positions, ce qui revient à diviser fp_val par 2^fr_bits.
    return static_cast<float>(this->fp_val) / (1 << this->fr_bits);
}

int Fixed::toInt(void) const
{
    // Pour effectuer cette conversion, la fonction divise d'abord 
    // fp_val par 1 << fr_bits, ce qui revient à diviser 
    // fp_val par 2^fr_bits. La valeur arrondie est renvoyee.
    return ((int)(roundf((float)this->fp_val / (1 << this->fr_bits))));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
