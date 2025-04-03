/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:23:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 16:03:27 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstdlib>
# include <iostream>
# include <string>

# define ARG_MSG "try ./zombie or ./zombie [number of zombies]"
# define NBR_MSG "Let's do 10 instead!\n"

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
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
