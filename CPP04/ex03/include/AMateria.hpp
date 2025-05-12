/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:34:01 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/12 15:11:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ICharacter.hpp"
# include <iostream>

class AMateria
{
/*****************
*    PROTECTED   *
*****************/
protected:

	std::string	_type;

/*****************
*     PUBLIC     *
*****************/
public:
	
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& object);
	~AMateria();

	AMateria&	operator=(const AMateria& object);

	const std::string&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};
