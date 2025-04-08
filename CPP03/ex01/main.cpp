/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:31:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/08 19:27:21 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a("wall-e");
	ClapTrap b("eve");

	for (size_t i = 0; i < 10; i++)
	{
		a.attack(b.getName());
		b.takeDamage(1);
	}

	ScavTrap c("bender");
	ScavTrap d("R2-D2");
	
	c.attack(d.getName());
	d.takeDamage(110);
	d.beRepaired(1);
	c.attack(d.getName());
	d.takeDamage(1);
	
	return (0);
}
