/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 16:30:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource
{
/*****************
*     PUBLIC     *
*****************/
public:

	MateriaSource();
	MateriaSource(const MateriaSource& object);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& object);
	
	virtual void 		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const & type);

};
