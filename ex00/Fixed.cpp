#include "Fixed.hpp"

int ft_pow(int num, int power)
{
    if (power <= 1)
        return num;
    else
        return num * ft_pow(num, power-1);
}

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.value;
}

Fixed &Fixed::operator=(Fixed& fixed)
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


int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw * ft_pow(2, 8);
}



