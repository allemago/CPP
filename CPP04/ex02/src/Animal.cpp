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

#include "../include/Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << CYAN "Animal" RESET << " default constructor called";
    std::cout << " for " << this->_type << std::endl;
}

Animal::Animal(const std::string name) : _type(name)
{
    std::cout << CYAN "Animal" RESET << " constructor with parameter called";
    std::cout << " for " << this->_type << std::endl;
}

Animal::Animal(const Animal& object)
{
    *this = object;
}

Animal::~Animal(void)
{
    std::cout << CYAN << "Animal " << RESET << "destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& object)
{
    if (this != &object)
    {
        this->_type = object._type;
    }
    std::cout << CYAN "Animal" RESET << " copy assignment operator called";
    std::cout << " for " << this->_type << std::endl;
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << CYAN << _type << RESET << " makes a sound 🐖" << std::endl;
}

void    Animal::printIdea(int idx) const { (void)idx; }

const std::string&    Animal::getType(void) const
{
    return (this->_type);
}
