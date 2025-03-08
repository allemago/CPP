/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:28:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 23:18:05 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << ARG_MSG << std::endl;
		return (1);
	}
	Harl complainer(argv[1]);
	complainer.complain(argv[1]);
	return (0);
}
