/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:37:52 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void)
{
	int N = 10;
	Zombie* horde = zombieHorde(N, "walker");
	delete[] horde;
	return (0);
}
