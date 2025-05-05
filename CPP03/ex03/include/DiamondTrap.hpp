/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:14:37 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 10:47:44 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <iomanip>

class DiamondTrap : public ScavTrap, public FragTrap
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string	_name;

/*****************
*     PUBLIC     *
*****************/
public:
	
	DiamondTrap(void);
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap& object);
	virtual	~DiamondTrap(void);

	DiamondTrap& operator=(const DiamondTrap& object);

	void	whoAmI(void);
	void	attack(const std::string& target);
	void	displayStatus(void) const;
};

#endif
