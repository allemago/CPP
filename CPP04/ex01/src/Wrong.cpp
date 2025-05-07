/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:08:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 15:13:57 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Wrong.hpp"

/* ************************************************************************** */
/*                               WrongAnimal                                  */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                               WrongCat                                     */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    displayStatus(" default constructor called");
}

WrongCat::WrongCat(const std::string name) : WrongAnimal(name)
{
    displayStatus(" constructor with parameter called");
}

WrongCat::WrongCat(const WrongCat& object) : WrongAnimal(object._type)
{
    *this = object;
    displayStatus(" copy constructor called");
}

WrongCat::~WrongCat(void)
{
    std::cout << PURPLE << "WrongCat " << RESET << "destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& object)
{
    if (this != &object)
    {
        WrongAnimal::operator=(object);
    }
    displayStatus(" copy assignment operator called");
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << PURPLE << _type << RESET << " purrs 🐈" << std::endl;
}

void    WrongCat::displayStatus(std::string constructor) const
{
	std::cout << PURPLE << "WrongCat" << RESET << constructor << std::endl;
}
