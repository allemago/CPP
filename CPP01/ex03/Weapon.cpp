/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:31 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/07 15:33:37 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

std::string& const Weapon::getType(void)
{
	return (type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	
}
