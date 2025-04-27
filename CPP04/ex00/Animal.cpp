/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:43:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 12:43:32 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    displayStatus(" default constructor called");
}

Animal::Animal(const std::string& name) : _type(name)
{
    displayStatus(" constructor with parameter called");
}

Animal::Animal(const Animal& object)
{
    *this = object;
    displayStatus(" copy constructor called");
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

Animal::~Animal(void)
{
    std::cout << CYAN << _type << RESET << " was destroyed" << std::endl;
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
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << CYAN << _type << RESET << constructor << std::endl;
	std::cout << this->_type << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}
