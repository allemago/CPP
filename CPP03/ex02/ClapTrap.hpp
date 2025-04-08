/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:40 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/09 01:11:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

class ClapTrap
{
	/*************
     * PROTECTED *
     *************/
	protected:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	
	/************
     *  PUBLIC  *
     ************/
	public:

	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& object);
	virtual	~ClapTrap(void);

	ClapTrap&	operator=(const ClapTrap& object);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string&	getName(void);
	void			displayStatus(void) const;
};

#endif
