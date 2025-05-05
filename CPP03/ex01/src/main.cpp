/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:31:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 12:29:19 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int	main(void)
{
	ScavTrap c("bender");
	ScavTrap d("R2-D2");
	d.guardGate();
	
	c.attack(d.getName());
	d.takeDamage(110);
	d.beRepaired(1);
	c.attack(d.getName());
	d.takeDamage(1);
	d.attack(c.getName());
	
	return (0);
}
