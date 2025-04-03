/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:27:56 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 13:40:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed&  Fixed::operator=(const Fixed& object)
{
    if (&object != this)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_value = object.getRawBits();
    }
    return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& object)
{
    os << object.toFloat();
    return (os);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float   Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _bits));
}

int   Fixed::toInt(void) const
{
    return (_value / (1 << _bits));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
