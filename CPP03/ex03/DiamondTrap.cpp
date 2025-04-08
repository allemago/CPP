/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:15:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/09 01:12:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->_name = "diamond_robot";
    this->_hitPoints = this->FragTrap::_hitPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackDamage = this->FragTrap::_attackDamage;

    displayStatus();
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = "diamond_robot";
    this->_hitPoints = this->FragTrap::_hitPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackDamage = this->FragTrap::_attackDamage;

    displayStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap& object) : ClapTrap(object._name + "_clap_name"), ScavTrap(object._name + "_clap_name"), FragTrap(object._name + "_clap_name")
{
    *this = object;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
    std::cout << BLUE << "DiamondTrap " << RESET BOLD << "destructor called" << std::endl;
	std::cout << this->_name << RED << " was destroyed" << RESET << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& object)
{
    if (this != &object)
    {
        this->_name = object._name;
		this->_hitPoints = object._hitPoints;
		this->_energyPoints = object._energyPoints;
		this->_attackDamage = object._attackDamage;
		this->_guardMode = object._guardMode;
    }
    displayStatus();
    return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is " << BOLD << this->_name << RESET;
	std::cout << " and my ClapTrap name is " << BOLD << this->ClapTrap::_name << RESET << std::endl;
}

void    DiamondTrap::displayStatus(void) const
{
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << BLUE << "DiamondTrap " << RESET BOLD << "constructor called" << std::endl;
	std::cout << this->_name << YELLOW << " was created" <<  RESET << std::endl;
	std::cout << "Hit point(s): " << this->_hitPoints << std::endl;
	std::cout << "Energy point(s): " << this->_energyPoints << std::endl;
	std::cout << "Damage point(s): " << this->_attackDamage << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << '-' << std::endl;
	std::cout << std::endl;
}
