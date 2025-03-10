/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:27:56 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/10 15:59:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(value << bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value(roundf(value * (1 << bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object)
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(object);
}

Fixed&  Fixed::operator=(const Fixed& object)
{
    if (&object != this)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->value = object.value;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Fixed& object)
{
    os << object.toFloat();
    return (os);
}

float   Fixed::toFloat(void) const
{
    return (value / (float)(1 << bits));
}

int   Fixed::toInt(void) const
{
    return (value / (1 << bits));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
