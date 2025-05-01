/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:54 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 13:45:47 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club) : _humanName(name), _currentWeapon(club) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	std::cout << _humanName << " attacks with their " << _currentWeapon.getType() << std::endl;
}
