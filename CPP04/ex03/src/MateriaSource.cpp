/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:51:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/12 14:19:16 by magrabko         ###   ########.fr       */
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
	delete _learnedMateria;
}

void	MateriaSource::initMaterias()
{
	for (int i = 0; i < 4; i ++)
		_learnedMateria[i] = NULL;
	_materiasCount = 0;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& object)
{
	if (this != &object)
	{
		if (this->_materiasCount)
			delete _learnedMateria, this->_materiasCount = 0;
		for (int i = 0; i < object._materiasCount; i++)
			learnMateria(object._learnedMateria[this->_materiasCount]);
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m && _materiasCount < 4)
		_learnedMateria[_materiasCount++] = m->clone();
	else if (_materiasCount == 4)
		std::cout << CANNOT_LEARN_MSG << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learnedMateria[i] && _learnedMateria[i]->getType() == type)
			return (_learnedMateria[i]->clone());
		i++;
	}
	return (NULL);
}
