/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/13 15:46:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <iostream>

# define CANNOT_LEARN_MSG "Cannot learn a Materia, inventory is full"
# define NOTLEARNED_TYPE_MSG "You have to learn a Materia before creating it, available: [ ice | cure ]."
# define UNDEFINED_TYPE_MSG "Please choose a valid Materia: [ ice | cure ]."

class MateriaSource : public IMateriaSource
{
/*****************
*     PRIVATE    *
*****************/
private:

	AMateria*	_learnedMaterias[4];
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
	void				deleteMaterias();
};
