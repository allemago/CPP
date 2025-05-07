/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:09:44 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 16:50:39 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{
/*****************
*     PRIVATE    *
*****************/
private:

	std::string	_name;
	AMateria*	_items;
	int			_itemCount;

/*****************
*     PUBLIC     *
*****************/
public:

	Character();
	Character(const std::string& name);
	Character(const Character& object);
	~Character();

	Character&	operator=(const Character& object);

	virtual const std::string&	getName() const;
	virtual void 				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

};
