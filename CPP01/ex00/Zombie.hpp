/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:38:18 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/06 15:14:15 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstdlib>
# include <iostream>
# include <string>

class Zombie
{
	public:

	Zombie(std::string name);
	~Zombie(void);
	
	void announce(void);

	private:
	
	std::string	name;
};

#endif
