#pragma once
#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed& fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int value;
        static const int fBits = 8;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
int ft_pow(int num, int power);
