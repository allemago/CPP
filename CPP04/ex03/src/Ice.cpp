/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:51 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 16:08:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& object) : AMateria("ice")
{
	*this = object;
}

Ice::~Ice() {}

Ice&	Ice::operator=(const Ice& object)
{
	if (this != &object)
	{
		AMateria::operator=(object);
		this->_type = object._type;
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
