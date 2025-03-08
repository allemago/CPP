/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:07:06 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 22:25:11 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl complains;
	for (size_t i = 0; i < 4; i++)
		complains.complain(complains.levels[i]);
	complains.complain("TEST");
	return (0);
}
