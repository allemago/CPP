/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:34:34 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 16:02:03 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("no_type") {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& object)
{
	*this = object;
}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& object)
{
	if (this != &object)
		this->_type = object._type;
	return (*this);
}

const std::string&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {}
