/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:36:17 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/12 15:02:20 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const int value) : value(value << bits) {}

Fixed::Fixed(const float value) : value(roundf(value * (1 << bits))) {}

Fixed::Fixed(const Fixed& object)
{
    operator=(object);
}

Fixed&  Fixed::operator=(const Fixed& right)
{
    if (&right != this)
    {
        this->value = right.value;
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Fixed& object)
{
    os << object.toFloat();
    return (os);
}

bool   Fixed::operator>(const Fixed& right)
{
    return (this->value > right.value);
}

bool   Fixed::operator<(const Fixed& right)
{
    return (this->value < right.value);
}

bool   Fixed::operator>=(const Fixed& right)
{
    return (this->value >= right.value);
}

bool   Fixed::operator<=(const Fixed& right)
{
    return (this->value <= right.value);
}

bool    Fixed::operator==(const Fixed& right)
{
    return (this->value == right.value);
}

bool    Fixed::operator!=(const Fixed& right)
{
    return (this->value != right.value);
}

Fixed   Fixed::operator+(const Fixed& right)
{
    Fixed result;
    
    result.value = (this->value + right.value);    
    return (result);
}

Fixed   Fixed::operator-(const Fixed& right)
{
    Fixed result;

    result.value = (this->value - right.value);    
    return (result);
}

Fixed   Fixed::operator*(const Fixed& right)
{
    Fixed result;
    
    result.value = ((this->value * right.value) >> bits);
    return (result);
}

Fixed   Fixed::operator/(const Fixed& right)
{
    Fixed result;
    
    if (right.value == 0)
    {
        std::cerr << "Error: cannot divide by zero." << std::endl;
        return (result);
    }
    result.value = ((this->value << bits) / right.value);
    return (result);
}

/******************************
*          PREFIXES           *
*******************************/
Fixed&  Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    this->value--;
    return (*this);
}
/******************************/

/******************************
*          SUFFIXES           *
*******************************/
Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    
    this->value++;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);

    this->value--;
    return (tmp);
}
/******************************/

Fixed& Fixed::min(Fixed& object1, Fixed& object2)
{
    return ((object1.value > object2.value) ? object2 : object1);
}

const Fixed&   Fixed::min(const Fixed& object1, const Fixed& object2)
{
    return ((object1.value > object2.value) ? object2 : object1);
}

Fixed& Fixed::max(Fixed& object1, Fixed& object2)
{
    return ((object1.value > object2.value) ? object1 : object2);
}

const Fixed&   Fixed::max(const Fixed& object1, const Fixed& object2)
{
    return ((object1.value > object2.value) ? object1 : object2);
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(value) / (1 << bits));
}

Fixed::~Fixed(void) {}
