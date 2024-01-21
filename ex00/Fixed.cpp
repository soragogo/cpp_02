#include "Fixed.hpp"

Fixed::Fixed() :value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = fixed.getRawBits();
}

Fixed &Fixed::operator=(Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw * (1 << fBits);
}



