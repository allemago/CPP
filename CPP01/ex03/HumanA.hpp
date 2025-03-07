/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:45 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/07 15:22:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public:
	
	HumanA(std::string name, Weapon club);
	~HumanA(void);

	void attack(void);
	
	private:
	
	std::string	name;
	Weapon weapon;
};

#endif
