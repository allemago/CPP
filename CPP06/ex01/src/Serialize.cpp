/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:06:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/01 15:50:41 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serialize.hpp"

Serialize::Serialize() {}

Serialize::Serialize(const Serialize& object)
{
	*this = object;
}

Serialize::~Serialize() {}

Serialize&	Serialize::operator=(const Serialize& object)
{
	(void)object;
	return (*this);
}

uintptr_t	Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
