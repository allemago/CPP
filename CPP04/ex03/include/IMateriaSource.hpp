/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:50:16 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 16:27:36 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class IMateriaSource
{
/*****************
*     PUBLIC     *
*****************/
public:

	virtual ~IMateriaSource() {}
	
	virtual void 		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;

};
