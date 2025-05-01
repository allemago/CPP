/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:13 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 13:45:53 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
	/*************
     *  PRIVATE  *
     *************/
	private:
	
	std::string		_humanName;
	Weapon			*_currentWeapon;
	
	/************
     *  PUBLIC  *
     ************/
	public:
	
	HumanB(std::string name);
	~HumanB(void);

	void attack(void);
	void setWeapon(Weapon& club);
};

#endif
