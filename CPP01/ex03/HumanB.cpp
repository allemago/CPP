/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/07 15:34:06 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanB::~HumanB(void)
{
	
}
