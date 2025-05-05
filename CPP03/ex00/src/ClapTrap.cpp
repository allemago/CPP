/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 12:18:51 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("robot"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	displayStatus();
}

ClapTrap::ClapTrap(const ClapTrap& object)
{
	*this = object;
	displayStatus();
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	displayStatus();
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << BOLD << this->_name << RED << " was destroyed" << RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& object)
{
	if (this != &object)
	{
		this->_name = object._name;
		this->_hitPoints = object._hitPoints;
		this->_energyPoints = object._energyPoints;
		this->_attackDamage = object._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		((_hitPoints -= amount) >= 0) ? _hitPoints : (_hitPoints = 0);
		std::cout << BOLD << _name << RESET << " gets " << amount << " point(s) of damage, ";
		std::cout << _hitPoints << " hit point(s) remaining" << std::endl;
	}
	else
		std::cout << "Cannot take damage: " << BOLD << _name << RESET << " is already dead 🤖" << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "Cannot repair: " << BOLD << _name << RESET <<  " is dead 🤖" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "Cannot repair: " << BOLD << _name << RESET <<  " doesn't have enough energy points" << std::endl;
	else
	{
		_energyPoints -= 1;
		_hitPoints += amount;
		std::cout << BOLD << this->_name << RESET << " gained " << amount << " hit point(s), ";
		std::cout << _hitPoints << " hit point(s) remaining" << std::endl;	
	}
	std::cout << std::endl;

}

std::string&	ClapTrap::getName(void)
{
	return (this->_name);
}

void	ClapTrap::displayStatus(void) const
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << BOLD << this->_name << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << "Hit point(s): " << this->_hitPoints << std::endl;
	std::cout << "Energy point(s): " << this->_energyPoints << std::endl;
	std::cout << "Damage point(s): " << this->_attackDamage << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}
