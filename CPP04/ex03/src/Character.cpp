/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:51:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/12 15:10:08 by magrabko         ###   ########.fr       */
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
	for (int i = 0; i < _materiasCount; i++)
		delete _materias[i];
	for (int i = 0; i < _droppedCount; i++)
		delete _droppedMaterias[i];
}

void	Character::initMaterias()
{
	for (int i = 0; i < 4; i ++)
		_materias[i] = NULL, _droppedMaterias[i] = NULL;
	_materiasCount = 0;
	_droppedCount = 0;
}


Character&	Character::operator=(const Character& object)
{
	if (this != &object)
	{
		this->_name = object.getName();
		if (_materiasCount)
			delete _materias, _materiasCount = 0;
		for (int i = 0; i < 4; i++)
			equip(object._materias[i]);
	}
	return (*this);
}

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (m && _materiasCount < 4)
		this->_materias[_materiasCount] = m->clone();
	else if (_materiasCount < 4)
		std::cout << CANNOT_EQUIP_MSG << std::endl;
}

void	Character::unequip(int idx)
{
	if (_materiasCount && idx >= 0 && idx < 4)
		_droppedMaterias[_droppedCount++] = _materias[idx];
	_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_materias[idx])
		this->_materias[idx]->use(target);
}
