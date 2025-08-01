/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:54 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:23:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    displayStatus(" default constructor called");
}

Cat::Cat(const std::string name) : Animal(name)
{
    displayStatus(" constructor with parameter called");
}

Cat::Cat(const Cat& object) : Animal(object._type)
{
    *this = object;
    displayStatus(" copy constructor called");
}

Cat::~Cat(void)
{
    std::cout << PURPLE << "Cat " << RESET << "destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& object)
{
    if (this != &object)
    {
        this->Animal::operator=(object);
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
