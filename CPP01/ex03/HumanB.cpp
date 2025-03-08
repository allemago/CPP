/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 14:09:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : HumanName(name), CurrentWeapon(NULL) {}

void	HumanB::setWeapon(Weapon &club)
{
	CurrentWeapon = &club;
}

void	HumanB::attack(void)
{
	std::cout << HumanName << " attacks with their " << CurrentWeapon->getType() << std::endl;
}

HumanB::~HumanB(void) {}
