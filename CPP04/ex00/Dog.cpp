/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:47 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 12:40:29 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : _type("Dog")
{
    displayStatus(" default constructor called");
}

Dog::Dog(const std::string& name) : _type(name)
{
    displayStatus(" constructor with parameter called");
}

Dog::Dog(const Dog& object) : Animal(object)
{
    *this = object;
    displayStatus(" copy constructor called");
}

Dog& Dog::operator=(const Dog& object)
{
    if (this != &object)
    {
        Animal::operator=(object);
        this->_type = object._type;
    }
    displayStatus(" copy assignment constructor called");
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << GREEN << _type << RESET << " was destroyed" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << GREEN << _type << RESET << " barks 🐕" << std::endl;
}

const std::string&    Dog::getType(void) const
{
    return (this->_type);
}

void    Dog::displayStatus(std::string constructor) const
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << GREEN << _type <<  RESET << constructor << std::endl;
	std::cout << this->_type << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}