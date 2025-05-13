/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:51:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/13 17:38:33 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("no one")
{
	initMaterias();
}

Character::Character(const std::string& name) : _name(name)
{
	initMaterias();
}

Character::Character(const Character& object)
{
	initMaterias();
	*this = object;
}

Character::~Character()
{
	deleteMaterias();
}

void	Character::initMaterias()
{
	for (int i = 0; i < 4; i ++)
		_materias[i] = NULL;
	_materiasCount = 0;
	_droppedCount = 0;
}

void	Character::deleteMaterias()
{
	for (int i = 0; i < _materiasCount; i++)
		delete _materias[i];
	for (int i = 0; i < _droppedCount; i++)
		delete _droppedMaterias[i];
	initMaterias();
}

Character&	Character::operator=(const Character& object)
{
	if (this != &object)
	{
		this->_name = object.getName();
		if (this->_materiasCount)
			deleteMaterias();
		for (int i = 0; object._materias[i] && i < object._materiasCount; i++)
		{
			this->_materias[i] = object._materias[i]->clone();
			this->_materiasCount++;	
		}
	}
	return (*this);
}

const AMateria*	Character::getMaterias() const
{
	return (*this->_materias);
}

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < _materiasCount; i++)
	{
		if (_materias[i] == m)
		{
			_materias[_materiasCount++] = m->clone();
			printMaterias();
			return ;
		}
	}
	if (m && _materiasCount < 4)
		_materias[_materiasCount++] = m;
	else if (_materiasCount >= 4)
		std::cout << CANNOT_EQUIP_MSG << std::endl;
	printMaterias();
}

void	Character::unequip(int idx)
{
	if (_materiasCount && idx >= 0 && idx < 4 && idx < _materiasCount)
	{
		if (_droppedCount < 20)
		{
			_droppedMaterias[_droppedCount++] = _materias[idx];
			_materias[idx] = NULL;
		}
		else
			std::cout << CANNOT_UNEQUIP_MSG << std::endl;
	}
	else if (!_materiasCount)
		std::cout << EMPTY_INVENT_MSG << std::endl;
	else
		std::cout << INDEX_UNEQUIP_MSG << _materiasCount << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_materias[idx])
		this->_materias[idx]->use(target);
	else
		std::cout << "* " << this->_name << NO_MATERIA_MSG << std::endl;
}

void	Character::printMaterias() const
{
	if (_materiasCount)
	{
		std::cout << getName() << "'s inventory:" << std::endl;
		for (int i = 0; i < _materiasCount; i++)
		{
			std::cout << i << " -> " << _materias[i]->getType();
			std::cout << " -> address " << _materias[i] << std::endl;
		}
		std::cout << std::endl;
	}
}
