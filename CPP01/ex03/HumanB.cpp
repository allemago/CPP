/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 16:07:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _humanName(name), _currentWeapon(NULL) {}

void	HumanB::setWeapon(Weapon &club)
{
	_currentWeapon = &club;
}

void	HumanB::attack(void)
{
	std::cout << _humanName << " attacks with their " << _currentWeapon->getType() << std::endl;
}

HumanB::~HumanB(void) {}
