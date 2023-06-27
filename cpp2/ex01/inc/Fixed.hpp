#pragma once
#ifndef FIXED_HPP

#include <iostream>
#include <bitset>

class Fixed
{
	int fp_val;
	static const int fr_bits;

  public:
	Fixed();
	Fixed(const int int_to_fp);
	Fixed(const float float_to_fp);
    ~Fixed();
    Fixed(const Fixed& nb);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void);
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif // !FIXED_HPP
