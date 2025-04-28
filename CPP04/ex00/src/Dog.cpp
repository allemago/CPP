/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:47 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 11:51:54 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    _type = "Dog";
    displayStatus(" default constructor called");
}

Dog::Dog(const Dog& object) : Animal(object)
{
    this->_type = object._type;
    displayStatus(" copy constructor called");
}

Dog::~Dog(void)
{
    std::cout << GREEN << "Dog " << RESET << "destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& object)
{
    if (this != &object)
    {\
        Animal::operator=(object);
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
