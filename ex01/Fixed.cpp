#include "Fixed.hpp"


Fixed::Fixed() :value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) :value(fixed.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) :value(value * 1 << fBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) :value(std::roundf(value * (1 << fBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

