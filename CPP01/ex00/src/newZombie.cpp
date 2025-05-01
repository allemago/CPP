/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:11 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:37:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}
