/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:52:03 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 09:52:30 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << CYAN "WrongAnimal" RESET << " default constructor called";
    std::cout << " for " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string name) : _type(name)
{
    std::cout << CYAN "WrongAnimal" RESET << " constructor with parameter called";
    std::cout << " for " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
{
    *this = object;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << CYAN << "WrongAnimal " << RESET << "destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& object)
{
    if (this != &object)
    {
        this->_type = object._type;
    }
    std::cout << CYAN "WrongAnimal" RESET << " copy assignment operator called";
    std::cout << " for " << this->_type << std::endl;
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << CYAN << _type << RESET << " makes a sound 🐖" << std::endl;
}

const std::string&    WrongAnimal::getType(void) const
{
    return (this->_type);
}