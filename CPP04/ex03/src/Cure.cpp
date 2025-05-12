/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/12 13:32:19 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& object) : AMateria("cure")
{
	*this = object;
}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& object)
{
	if (this != &object)
	{
		AMateria::operator=(object);
		this->_type = object._type;
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	AMateria::use(ICharacter& target)
{
	std::cout << " heals " << target.getName() << "’s wounds *" << std::endl;
}
