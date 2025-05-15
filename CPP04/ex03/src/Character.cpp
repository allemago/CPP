/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:51:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 17:29:28 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("NO_ONE")
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
}

Character&	Character::operator=(const Character& object)
{
	if (this != &object)
	{
		this->_name = object.getName();
		if (this->_materiasCount)
			deleteMaterias(), initMaterias();
		for (int i = 0; object._materias[i] && i < object._materiasCount; i++)
		{
			this->_materias[i] = object._materias[i]->clone();
			this->_materiasCount++;	
		}
	}
	return (*this);
}

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	std::cout << BOLD "equip called, " RESET;
	bool isFull = true;
	if (_materiasCount < 4)
	{
		isFull = false;
		_materias[_materiasCount++] = m->clone();
		printMaterias();
	}
	else
	{
		for (int i = 0; i < _materiasCount; i++)
		{
			if (!_materias[i])
			{
				isFull = false;
				_materias[i] = m->clone();
				printMaterias();
				break ;
			}
		}
	}
	delete m;
	if (isFull)
		std::cout << CANNOT_EQUIP_MSG << std::endl;
}

void	Character::unequip(int idx)
{
	std::cout << BOLD "unequip called, " RESET;
	if (idx < 0 || idx >= 4)
		std::cout << INDEX_UNEQUIP_MSG << _materiasCount -1 << std::endl;
	else if (_droppedCount == 20)
		std::cout << LIMIT_UNEQUIP_MSG << std::endl;
	else if (!_materiasCount)
		std::cout << EMPTY_MSG << std::endl;
	else if (!_materias[idx])
		std::cout << EMPTY_MATERIA_MSG << std::endl;
	else
	{
		_droppedMaterias[_droppedCount] = _materias[idx];
		_droppedCount++;
		_materias[idx] = NULL;
		printMaterias();
	}	
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
		bool empty = true;
		std::cout << getName() << " inventory:" << std::endl;
		for (int i = 0; i < _materiasCount; i++)
		{
			if (_materias[i])
			{
				empty = false;
				std::cout << _materias[i]->getType() << " -> address " << _materias[i] << std::endl;
			}
		}
		if (empty)
			std::cout << EMPTY_MSG << std::endl;;
	}
}

const AMateria*	Character::getMaterias() const
{
	return (*this->_materias);
}
