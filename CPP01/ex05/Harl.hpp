/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:08:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 22:32:48 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <cstring>
# include <iostream>
# include <string>

# define DEBUG_MSG "\033[1m[DEBUG]\033[0m\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO_MSG "\033[1m[INFO]\033[0m\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING_MSG "\033[1m[WARNING]\033[0m\nthink I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR_MSG "\033[1m[ERROR]\033[0m\nThis is unacceptable! I want to speak to the manager now."
# define UNKNOWN_MSG1 "\033[1m["
# define UNKOWNK_MSG2 "]\033[0m\nProbably complaining about insignificant problems."

class Harl
{
  public:
  
  	Harl(void);
	~Harl(void);

	std::string levels[4];
	void (Harl::*functions[4])();
	
	void complain(std::string level);

  private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
