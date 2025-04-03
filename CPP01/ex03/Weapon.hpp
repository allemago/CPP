/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:22 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 16:06:06 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <cstdlib>
# include <iostream>
# include <cstring>

class Weapon
{
	/*************
     *  PRIVATE  *
     *************/
	private:

	std::string	_type;

	/************
     *  PUBLIC  *
     ************/
	public:

	Weapon(std::string type);
	~Weapon(void);

	const std::string& getType(void) const;
	void setType(std::string type);
};

#endif
