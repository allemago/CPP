/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:47 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:22:16 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    displayStatus(" default constructor called");
}

Dog::Dog(const std::string name) : Animal(name)
{
    displayStatus(" constructor with parameter called");
}

Dog::Dog(const Dog& object) : Animal(object._type)
{
    *this = object;
    displayStatus(" copy constructor called");
}

Dog::~Dog(void)
{
    std::cout << GREEN << "Dog " << RESET << "destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& object)
{
    if (this != &object)
    {
        this->Animal::operator=(object);
    }
    displayStatus(" copy assignment operator called");
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << GREEN << _type << RESET << " barks 🐕" << std::endl;
}

void    Dog::displayStatus(std::string constructor) const
{
	std::cout << GREEN << "Dog" <<  RESET << constructor << std::endl;
}
