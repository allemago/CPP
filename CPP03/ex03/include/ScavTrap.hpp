/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:36:19 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 11:55:00 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

class ScavTrap : virtual public ClapTrap
{
/*****************
*     PUBLIC     *
*****************/
public:

	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& object);
	virtual	~ScavTrap(void);

	ScavTrap& operator=(const ScavTrap& object);

	void	attack(const std::string& target);
	void	guardGate(void);
	void	displayStatus(void) const;
};

#endif
