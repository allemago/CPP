/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:31 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 13:58:27 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}
