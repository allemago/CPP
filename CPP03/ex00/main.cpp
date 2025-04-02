/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:31:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/02 18:30:49 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("wall-e");
	ClapTrap b("eve");

	for (size_t i = 0; i < 10; i++)
	{
		a.attack(b.getName());
		b.takeDamage(1);
	}
	
	a.attack(b.getName());
	b.takeDamage(1);
	b.beRepaired(1);
	a.attack(b.getName());
	b.takeDamage(1);
	
	return (0);
}
