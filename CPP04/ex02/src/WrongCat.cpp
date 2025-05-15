/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:08:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:00:59 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

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
