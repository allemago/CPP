/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:36:17 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/04 12:05:36 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void)
{
    setRawBits(0);
}

Fixed::Fixed(const int value) : _value(value << _bits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits))) {}

Fixed::Fixed(const Fixed& object)
{
    *this = object;
}

Fixed::~Fixed(void) {}

Fixed&  Fixed::operator=(const Fixed& right)
{
    if (&right != this)
    {
        this->_value = right.getRawBits();
    }
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Fixed& object)
{
    os << object.toFloat();
    return (os);
}

bool   Fixed::operator>(const Fixed& right) const
{
    return (this->_value > right._value);
}

bool   Fixed::operator<(const Fixed& right) const
{
    return (this->_value < right._value);
}

bool   Fixed::operator>=(const Fixed& right) const
{
    return (this->_value >= right._value);
}

bool   Fixed::operator<=(const Fixed& right) const
{
    return (this->_value <= right._value);
}

bool    Fixed::operator==(const Fixed& right) const
{
    return (this->_value == right._value);
}

bool    Fixed::operator!=(const Fixed& right) const
{
    return (this->_value != right._value);
}

Fixed   Fixed::operator+(const Fixed& right) const
{
    Fixed result;
    
    result._value = (this->_value + right._value);    
    return (result);
}

Fixed   Fixed::operator-(const Fixed& right) const
{
    Fixed result;

    result._value = (this->_value - right._value);    
    return (result);
}

Fixed   Fixed::operator*(const Fixed& right) const
{
    Fixed result;
    
    result._value = ((this->_value * right._value) >> _bits);
    return (result);
}

Fixed   Fixed::operator/(const Fixed& right) const
{
    Fixed result;
    
    if (right._value == 0)
    {
        std::cerr << "Error: cannot divide by zero: ";
        std::cerr << this->_value << " / " << right._value << std::endl;
        return (result);
    }
    result._value = ((this->_value << _bits) / right._value);
    return (result);
}

/******************************
*          PREFIXES           *
*******************************/
Fixed&  Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed&  Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}
/******************************/

/******************************
*          SUFFIXES           *
*******************************/
Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    
    this->_value++;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);

    this->_value--;
    return (tmp);
}
/******************************/

Fixed& Fixed::min(Fixed& object1, Fixed& object2)
{
    return ((object1._value > object2._value) ? object2 : object1);
}

const Fixed&   Fixed::min(const Fixed& object1, const Fixed& object2)
{
    return ((object1._value > object2._value) ? object2 : object1);
}

Fixed& Fixed::max(Fixed& object1, Fixed& object2)
{
    return ((object1._value > object2._value) ? object1 : object2);
}

const Fixed&   Fixed::max(const Fixed& object1, const Fixed& object2)
{
    return ((object1._value > object2._value) ? object1 : object2);
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
