#pragma once
#include <iostream>

class Fixed{
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(Fixed& fixed);
        ~Fixed();
        int getRawBits(void);
        void setRawBits(int const raw);
    private:
        int value;
        static const int fBits = 8;

};

int ft_pow(int num, int power);
