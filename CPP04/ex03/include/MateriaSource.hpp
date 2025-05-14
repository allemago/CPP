/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/14 12:55:56 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "utils.hpp"
# include <iostream>

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
