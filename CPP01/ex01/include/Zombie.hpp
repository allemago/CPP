/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 14:24:44 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	/*************
     *  PRIVATE  *
     *************/
	private:

	std::string	_name;
	
	/************
     *  PUBLIC  *
     ************/
	public:

	Zombie(void);
	~Zombie(void);

	void	announce(void);
	void	setName(const std::string& name);
};

Zombie*		zombieHorde(int N, std::string name);

#endif
