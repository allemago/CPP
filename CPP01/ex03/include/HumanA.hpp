/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:45 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 13:45:51 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
	/*************
     *  PRIVATE  *
     *************/
	private:
	
	std::string		_humanName;
	Weapon			&_currentWeapon;
	
	/************
     *  PUBLIC  *
     ************/
	public:
	
	HumanA(std::string name, Weapon& club);
	~HumanA(void);

	void attack(void);
};

#endif
