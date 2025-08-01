/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:09:44 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/14 16:14:02 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "utils.hpp"
# include <iostream>

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

	virtual const std::string&	getName() const;
	virtual void 				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);
	
	void						initMaterias();
	void						deleteMaterias();
	
	// TEST //
	void						printMaterias() const;
	const AMateria*				getMaterias() const;
};
