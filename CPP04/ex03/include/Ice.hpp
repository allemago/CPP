/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:49:44 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 09:16:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Ice : public AMateria
{
/*****************
*     PUBLIC     *
*****************/
public:

	Ice();
	Ice(const Ice& object);
	~Ice();

	Ice&	operator=(const Ice& object);
	
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};
