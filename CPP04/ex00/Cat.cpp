/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:54 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 12:40:22 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : _type("Cat")
{
    displayStatus(" default constructor called");
}

Cat::Cat(const std::string& name) : _type(name)
{
    displayStatus(" constructor with parameter called");
}

Cat::Cat(const Cat& object) : Animal(object)
{
    *this = object;
    displayStatus(" copy constructor called");
}

Cat& Cat::operator=(const Cat& object)
{
    if (this != &object)
    {
        Animal::operator=(object);
        this->_type = object._type;
    }
    displayStatus(" copy assignment operator called");
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << PURPLE << _type << RESET << " was destroyed" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << PURPLE << _type << RESET << " purrs 🐈" << std::endl;
}

const std::string&    Cat::getType(void) const
{
    return (this->_type);
}

void    Cat::displayStatus(std::string constructor) const
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << PURPLE << _type << RESET << constructor << std::endl;
	std::cout << this->_type << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}
