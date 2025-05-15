/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:47 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:36:47 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain)
{
    displayStatus(" default constructor called");
}

Dog::Dog(const std::string name) : Animal(name), _brain(new Brain)
{
    displayStatus(" constructor with parameter called");
}

Dog::Dog(const std::string idea, const size_t i) : Animal("Dog"), _brain(new Brain(idea, i))
{
    displayStatus(" constructor with parameter called");
}

Dog::Dog(const Dog& object) : Animal(object._type), _brain(NULL)
{
    *this = object;
    displayStatus(" copy constructor called");
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << GREEN << "Dog " << RESET << "destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& object)
{
    if (this != &object)
    {
        this->Animal::operator=(object);
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*object._brain);
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
