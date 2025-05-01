/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:28 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:38:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].announce();	
	}
	return (horde);
}
