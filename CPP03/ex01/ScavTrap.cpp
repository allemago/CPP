/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:36:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/09 01:11:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    this->_guardMode = false;

    displayStatus();
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{   
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    displayStatus();
}

ScavTrap::ScavTrap(const ScavTrap& object) : ClapTrap(object)
{
    *this = object;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
    std::cout << CYAN << "ScavTrap " << RESET BOLD << "destructor called" << std::endl;
	std::cout << this->_name << RED << " was destroyed" << RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& object)
{
    if (this != &object)
    {
        ClapTrap::operator=(object);
        this->_guardMode = object._guardMode;
    }
    displayStatus();
    return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
    std::cout << CYAN << "ScavTrap " << RESET BOLD << "attack called" << std::endl;
	if (_hitPoints == 0)
	{
		std::cout << "Cannot attack: " << BOLD << _name << RESET << " is dead 🤖";
		std::cout << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "Cannot attack: " << BOLD << _name << RESET << " doesn't have enough energy points";
		std::cout << std::endl;
	}
	else
	{
		_energyPoints -= 1;
		std::cout << BOLD << _name << RESET << " attacks " << BOLD << target << RESET;
		std::cout << " causing " << _attackDamage << " point(s) of damage" << std::endl;
		std::cout << "-1 energy point, remaining: " << _energyPoints << std::endl;
	}
	std::cout << std::endl;
}

void    ScavTrap::guardGate(void)
{
    this->_guardMode = true;
}

void    ScavTrap::displayStatus(void) const
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << CYAN << "ScavTrap " << RESET BOLD << "constructor called" << std::endl;
	std::cout << this->_name << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << "Hit point(s): " << this->_hitPoints << std::endl;
	std::cout << "Energy point(s): " << this->_energyPoints << std::endl;
	std::cout << "Damage point(s): " << this->_attackDamage << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}
