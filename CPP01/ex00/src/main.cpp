/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:09 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:40:41 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie *newbie = newZombie("heap");
	delete newbie;
	randomChump("stack");
	return (0);
}
