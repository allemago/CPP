/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/12 14:07:34 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include <iostream>

# define CANNOT_LEARN_MSG "You cannot learn a Materia, inventory is full"

class MateriaSource : public IMateriaSource
{
/*****************
*     PRIVATE    *
*****************/
private:

	AMateria*	_learnedMateria[4];
	int			_materiasCount;
	
/*****************
*     PUBLIC     *
*****************/
public:

	MateriaSource();
	MateriaSource(const MateriaSource& object);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& object);
	
	virtual void 		learnMateria(AMateria* m);
	virtual AMateria*	createMateria(const std::string& type);

	void				initMaterias();
};
