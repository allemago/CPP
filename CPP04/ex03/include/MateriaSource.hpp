/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/14 11:41:20 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <iostream>

# define BOLD "\033[1m"
# define RESET "\033[0m"
# define CANNOT_LEARN_MSG "cannot learn a Materia, inventory is full"
# define NOTLEARNED_TYPE_MSG "you have to learn a Materia before creating it: learnMateria [ ice | cure ]"
# define UNDEFINED_TYPE_MSG "please choose a valid Materia: [ ice | cure ]"

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
	void				printLearnedMaterias() const;
};
