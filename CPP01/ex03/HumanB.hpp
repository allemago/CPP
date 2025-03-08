/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:13 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 13:40:49 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
	
	HumanB(std::string name);
	~HumanB(void);

	void attack(void);
	void setWeapon(Weapon &club);

	private:
	
	std::string	HumanName;
	Weapon *CurrentWeapon;
};

#endif
