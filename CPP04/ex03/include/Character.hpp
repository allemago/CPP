/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:09:44 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/13 17:37:30 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

# define CANNOT_EQUIP_MSG "cannot equip a Materia, inventory is full"
# define CANNOT_UNEQUIP_MSG "unequip limit has been reach, restart the game if you want to play again!"
# define INDEX_UNEQUIP_MSG "cannot unequip, select a valid index between 0 and "
# define NO_MATERIA_MSG " has no materia available at this index *"
# define EMPTY_INVENT_MSG "cannot unequip, inventory is empty"

class Character : public ICharacter
{
/*****************
*     PRIVATE    *
*****************/
private:

	std::string	_name;
	AMateria*	_materias[4];
	AMateria*	_droppedMaterias[20];
	int			_materiasCount;
	int			_droppedCount;

/*****************
*     PUBLIC     *
*****************/
public:

	Character();
	Character(const std::string& name);
	Character(const Character& object);	
	~Character();

	Character&	operator=(const Character& object);

	virtual const AMateria*		getMaterias() const;
	virtual const std::string&	getName() const;
	virtual void 				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

	void						initMaterias();
	void						deleteMaterias();

	// TEST //
	void						printMaterias() const;
};
