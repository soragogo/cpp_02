#pragma once
#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed &operator=(const Fixed& fixed);
        bool operator>(const Fixed& fixed);
        bool operator<(const Fixed& fixed);
        bool operator>=(const Fixed& fixed);
        bool operator<=(const Fixed& fixed);
        bool operator==(const Fixed& fixed);
        bool operator!=(const Fixed& fixed);
        Fixed operator+(const Fixed& fixed);
        Fixed operator-(const Fixed& fixed);
        Fixed operator*(const Fixed& fixed);
        Fixed operator/(const Fixed& fixed);
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
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
