/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:54 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 13:40:28 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) : HumanName(name), CurrentWeapon(club) {}

void	HumanA::attack(void)
{
	std::cout << HumanName << " attacks with their " << CurrentWeapon.getType() << std::endl;
}

HumanA::~HumanA(void) {}
