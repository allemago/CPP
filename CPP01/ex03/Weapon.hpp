/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:22 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 14:11:29 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <cstring>

class Weapon
{
	public:

	Weapon(std::string type);
	~Weapon(void);

	const std::string& getType(void) const;
	void setType(std::string type);
	
	private:

	std::string type;
};

#endif
