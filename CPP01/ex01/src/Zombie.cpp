/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:33 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:37:57 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	this->_name = name;
}
