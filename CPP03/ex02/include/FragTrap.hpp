/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:31:19 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/05 10:47:21 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

class FragTrap : public ClapTrap
{
/*****************
*     PUBLIC     *
*****************/
public:
	
	FragTrap(void);
	FragTrap(const std::string name);
	FragTrap(const FragTrap& object);
	virtual ~FragTrap(void);

	FragTrap& operator=(const FragTrap& object);

	void	highFivesGuys(void);
	void	displayStatus(void) const;
};

#endif
