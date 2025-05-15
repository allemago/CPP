/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:49:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 09:16:54 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure : public AMateria
{
/*****************
*     PUBLIC     *
*****************/
public:

	Cure();
	Cure(const Cure& object);
	~Cure();

	Cure&	operator=(const Cure& object);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
};