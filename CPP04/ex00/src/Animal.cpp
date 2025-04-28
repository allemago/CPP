 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:43:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 14:47:48 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    displayStatus(" default constructor called");
}

Animal::Animal(const Animal& object)
{
    *this = object;
}

Animal::~Animal(void)
{
    std::cout << CYAN << "Animal " << RESET << "destructor called" << std::endl;
	std::cout << std::setfill('-') << std::setw(40) << '-' << std::endl;
}

Animal& Animal::operator=(const Animal& object)
{
    if (this != &object)
    {
        this->_type = object._type;
    }
    displayStatus(" copy assignment operator called");
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << CYAN << _type << RESET << " makes a sound 🐖" << std::endl;
}

const std::string&    Animal::getType(void) const
{
    return (this->_type);
}

void    Animal::displayStatus(std::string constructor) const
{
	std::cout << std::setfill('-') << std::setw(40) << '-' << std::endl;
	std::cout << CYAN << "Animal" << RESET << constructor << std::endl;
}
