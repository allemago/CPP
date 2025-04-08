/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:31:22 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/08 20:09:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    displayStatus();
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{   
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    displayStatus();
}

FragTrap::FragTrap(const FragTrap& object) : ClapTrap(object)
{
    *this = object;
}

FragTrap::~FragTrap(void)
{
    std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
    std::cout << PURPLE << "FragTrap " << RESET BOLD << "destructor called" << std::endl;
	std::cout << this->_name << RED << " was destroyed" << RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& object)
{
    if (this != &object)
    {
        ClapTrap::operator=(object);
    }
    displayStatus();
    return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
		std::cout << "Cannot high five: " << this->_name << " is dead 🤖" << std::endl;
	else
		std::cout << BOLD << this->_name << RESET " gives a high five! 🖐️" << std::endl;
	std::cout << std::endl;
}

void    FragTrap::displayStatus(void) const
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << PURPLE << "FragTrap " << RESET BOLD << "constructor called" << std::endl;
	std::cout << this->_name << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << "Hit point(s): " << this->_hitPoints << std::endl;
	std::cout << "Energy point(s): " << this->_energyPoints << std::endl;
	std::cout << "Damage point(s): " << this->_attackDamage << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}
