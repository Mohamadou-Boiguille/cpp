#pragma once
#ifndef FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int fixed_v;
	static const int fractional_bits;

  public:
	Fixed();
	Fixed(const int int_to_fp);
	Fixed(const float float_to_fp);
    ~Fixed();
    Fixed(const Fixed& nb);

    Fixed operator=(const Fixed& other);
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed operator++(int);
    Fixed& operator++();

    static int min(int a, int b);
    static float min(float a, float b);
    static int max(int a, int b);
    static float max(float a, float b);

    static Fixed min(const Fixed& a, const Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);

    bool operator>(const Fixed& other);
    bool operator<(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator==(const Fixed& other);
    bool operator!=(const Fixed& other);

    void setRawBits(int const raw);
    int getRawBits(void) const;

    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif // !FIXED_HPP
