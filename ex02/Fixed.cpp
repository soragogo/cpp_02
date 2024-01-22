#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = fixed.getRawBits();
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->value = (value  << fBits);
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->value = std::roundf(value * (1 << fBits));
}

Fixed &Fixed::operator=(const Fixed& fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw * (1 << fBits);
}


float Fixed::toFloat(void) const
{
    float ret;
    ret = this->getRawBits();
    return (ret / (1 << fBits));
}

int Fixed::toInt(void) const
{
    return roundf(toFloat());
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& fixed)
{
    return this->value > fixed.value;
}

bool Fixed::operator<(const Fixed& fixed)
{
    return this->value < fixed.value;
}

bool Fixed::operator>=(const Fixed& fixed)
{
    return this->value >= fixed.value;
}

bool Fixed::operator<=(const Fixed& fixed)
{
    return this->value <= fixed.value;
}

bool Fixed::operator==(const Fixed& fixed)
{
    return this->value == fixed.value;
}

bool Fixed::operator!=(const Fixed& fixed)
{
    return this->value != fixed.value;
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    Fixed tmp(this->toFloat() + fixed.toFloat());
    return tmp;
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    Fixed tmp(this->toFloat() - fixed.toFloat());
    return tmp;
}
Fixed Fixed::operator*(const Fixed& fixed)
{
    Fixed tmp(this->toFloat() * fixed.toFloat());
    return tmp;
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    Fixed tmp(this->toFloat() / fixed.toFloat());
    return tmp;
}

Fixed &Fixed::operator++(void)
{
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++(*this);
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --(*this);
    return tmp;
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
    if (a.value < b.value)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.value < b.value)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
    if (a.value > b.value)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.value > b.value)
        return (a);
    else
        return (b);
}



