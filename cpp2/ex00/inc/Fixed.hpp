#pragma once
#ifndef FIXED_HPP

#include <iostream>

class Fixed
{
	int fixed_v;
	int bits_f;

  public:
	Fixed();
    ~Fixed();
    int getRawBits(void);
    void setRawBits(int const raw);
};

#endif // !FIXED_HPP
