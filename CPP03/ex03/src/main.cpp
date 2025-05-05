/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:31:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 12:28:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int	main(void)
{	
	DiamondTrap f;
	f.whoAmI();
	
	DiamondTrap g("robocop");
	g.whoAmI();
	g.attack(f.getName());
	g.takeDamage(12);
	g.highFivesGuys();

	return (0);
}
