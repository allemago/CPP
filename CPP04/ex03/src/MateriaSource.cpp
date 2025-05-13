/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:51:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/13 15:51:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	initMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& object)
{
	initMaterias();
	*this = object;
}

MateriaSource::~MateriaSource()
{
	deleteMaterias();
}

void	MateriaSource::initMaterias()
{
	for (int i = 0; i < 4; i ++)
		_learnedMaterias[i] = NULL;
	_materiasCount = 0;
}

void	MateriaSource::deleteMaterias()
{
	for (int i = 0; i < _materiasCount; i++)
		delete _learnedMaterias[i];
	initMaterias();
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& object)
{
	if (this != &object)
	{
		if (this->_materiasCount)
			deleteMaterias();
		for (int i = 0; object._learnedMaterias[i] && i < object._materiasCount; i++)
		{
			this->_learnedMaterias[i] = object._learnedMaterias[i]->clone();
			this->_materiasCount++;	
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m && _materiasCount < 4)
		_learnedMaterias[_materiasCount++] = m;
	else if (_materiasCount == 4)
		std::cout << CANNOT_LEARN_MSG << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; !type.empty() && i < 4; i++)
	{
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
			return (_learnedMaterias[i]->clone());
	}
	if (type == "ice" | type == "cure")
		std::cout << NOTLEARNED_TYPE_MSG << std::endl;
	else
		std::cout << UNDEFINED_TYPE_MSG << std::endl;
	return (NULL);
}
