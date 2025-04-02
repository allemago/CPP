/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:36:19 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/02 18:47:35 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <iomanip>

class ScavTrap
{
	private:
	
	void	guardGate(void);
	
	public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& object);
	~ScavTrap(void);

	ScavTrap& operator=(const ScavTrap& object);
};

#endif
