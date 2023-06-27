#pragma once
#ifndef FIXED_HPP

#include <iostream>
#include <cmath>

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

    Fixed &operator=(const Fixed& other);
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed operator++(int);
    Fixed& operator++();

    static Fixed min(Fixed& a, Fixed& b);
    static Fixed max(Fixed& a, Fixed& b);
    static Fixed min(const Fixed& a, const Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    void setRawBits(int const raw);
    int getRawBits(void) const;

    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif // !FIXED_HPP
