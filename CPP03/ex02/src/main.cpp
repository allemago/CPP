/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:31:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 12:28:40 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int	main(void)
{
	FragTrap e("terminator");
	FragTrap f("astro boy");
	
	e.attack(f.getName());
	f.takeDamage(10);
	f.beRepaired(1);
	e.attack(f.getName());
	f.takeDamage(1);
	f.highFivesGuys();
	
	return (0);
}
