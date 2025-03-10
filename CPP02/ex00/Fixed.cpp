/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:03:31 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/10 11:24:00 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void)
{
    setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object) : value(object.value)
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(object);
}

Fixed&   Fixed::operator=(const Fixed& object)
{
    if (&object != this)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->value = object.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
