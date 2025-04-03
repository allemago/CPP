/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:29:25 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 16:11:02 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstring>
# include <string>

# define ARG_MSG "usage: ./harlFilter [DEBUG | INFO | WARNING | ERROR]"
# define DEBUG_MSG "\033[1m[DEBUG]\033[0m\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO_MSG "\033[1m[INFO]\033[0m\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING_MSG "\033[1m[WARNING]\033[0m\nthink I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR_MSG "\033[1m[ERROR]\033[0m\nThis is unacceptable! I want to speak to the manager now."
# define UNKNOWN_MSG1 "\033[1m["
# define UNKNOWN_MSG2 "]\033[0m\nProbably complaining about insignificant problems."

class Harl
{
	/*************
     *  PRIVATE  *
     *************/
	private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	
	/************
     *  PUBLIC  *
     ************/
	public:

	Harl(const std::string level);
	~Harl(void);

	std::string levels[4];
	size_t		level_index;

	void complain(std::string level);
};


#endif
