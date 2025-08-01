/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:29:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:39:10 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(const std::string level)
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	
	level_index = 0;
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			level_index = i + 1;
			break ;
		}
	}
}

Harl::~Harl(void) {}

void	Harl::complain(std::string level)
{
	switch (level_index)
	{
		case 0:
			std::cout << UNKNOWN_MSG1 << level << UNKNOWN_MSG2 << std::endl;
			break ;
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
	}
}

void	Harl::debug(void)
{
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info(void)
{
	std::cout << INFO_MSG << std::endl;
}

void	Harl::warning(void)
{
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error(void)
{
	std::cout << ERROR_MSG << std::endl;
}
