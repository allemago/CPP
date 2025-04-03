/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 16:02:07 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstdlib>
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

	Zombie(std::string name);
	~Zombie(void);
	
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
