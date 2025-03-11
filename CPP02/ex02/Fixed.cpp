/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:36:17 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/11 14:13:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) {}

Fixed::Fixed(const int value) : value(value << bits) {}

Fixed::Fixed(const float value) : value(roundf(value * (1 << bits))) {}

Fixed::Fixed(const Fixed& object)
{
    operator=(object);
}

Fixed&  Fixed::operator=(const Fixed& object)
{
    if (&object != this)
    {
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

Fixed::~Fixed(void) {}
