/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:16 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:37:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
