/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:09 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/06 15:01:11 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie *newbie = new Zombie(name);
	newbie->announce();
	return (newbie);
}

void	randomChump(std::string name)
{
	Zombie random(name);
	random.announce();
}

int main(void)
{
	Zombie *newbie = newZombie("newbie");
	delete newbie;
	randomChump("random");
	return (0);
}
