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

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value * ft_pow(2, 8);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = value * ft_pow(2, 8);
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
    value = raw * ft_pow(2, 8);
}


float Fixed::toFloat(void) const
{
    float ret;
    ret = this->getRawBits();
    return (ret / ft_pow(2, 8));
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

