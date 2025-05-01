/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 13:59:15 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _humanName(name), _currentWeapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon& club)
{
	_currentWeapon = &club;
}

void	HumanB::attack(void)
{
	if (!_currentWeapon)
		std::cout << _humanName << " doesn't have a weapon" << std::endl;
	else
		std::cout << _humanName << " attacks with their " << _currentWeapon->getType() << std::endl;
}
