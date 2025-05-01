/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:22 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 13:45:24 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

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
	void setType(const std::string& type);
};

#endif
