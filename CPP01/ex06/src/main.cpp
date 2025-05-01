/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:28:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:39:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << ARG_MSG << std::endl, 1);
	Harl complainer(argv[1]);
	complainer.complain(argv[1]);
	return (0);
}
