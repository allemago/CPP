/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/06 19:25:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static int	getNumber(int argc, char *argv)
{
	long	N;
	
	if (argc == 1)
		return (10);
	N = atol(argv);
	if (N <= 0 || N > 1000000)
		return (std::cout << NBR_MSG << std::endl, 10);
	return (N);
}

int	main(int argc, char **argv)
{
	Zombie	*horde;
	long	N;
	
	if (argc > 2 || !(N = getNumber(argc, argv[1])))
		return (std::cerr << ARG_MSG << std::endl, 1);
	horde = zombieHorde(N, "newbie");
	delete[] horde;
	return (0);
}
