#pragma once
#ifndef FIXED_HPP

#include <iostream>
#include <bitset>

class Fixed
{
	int fixed_v;
	static const int fractional_bits;

  public:
	Fixed();
    Fixed(const Fixed& nb);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void);
    void setRawBits(int const raw);
};

#endif // !FIXED_HPP
