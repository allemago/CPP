/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:51:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 16:52:35 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("no one"), _items(NULL), _itemCount(0) {}

Character::Character(const std::string& name) : _name(name), _items(NULL), _itemCount(0) {}

Character::Character(const Character& object)
{
	*this = object;
}

Character::~Character()
{
	unequip(_itemCount);
}

Character&	Character::operator=(const Character& object)
{
	if (this != &object)
	{
		this->_name = object.getName();
		if (this->_items)
			equip(this->_items);
		this->_itemCount = object._itemCount;
	}
	return (*this);
}

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	this->_items = m;
}

void	Character::unequip(int idx)
{
	delete _items[idx];
}

void	Character::use(int idx, ICharacter& target)
{
	
}
