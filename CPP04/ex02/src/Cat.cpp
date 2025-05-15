/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:54 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:51:22 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain)
{
    displayStatus(" default constructor called");
}

Cat::Cat(const std::string name) : Animal(name), _brain(new Brain)
{
    displayStatus(" constructor with parameter called");
}

Cat::Cat(const std::string idea, const size_t i) : Animal("Cat"), _brain(new Brain(idea, i))
{
    displayStatus(" constructor with parameter called");
}

Cat::Cat(const Cat& object) : Animal(object._type), _brain(NULL)
{
    *this = object;
    displayStatus(" copy constructor called");
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << PURPLE << "Cat " << RESET << "destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& object)
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

void    Cat::makeSound(void) const
{
    std::cout << PURPLE << _type << RESET << " purrs 🐈" << std::endl;
}

void    Cat::displayStatus(std::string constructor) const
{
	std::cout << PURPLE << "Cat" << RESET << constructor << std::endl;
}
