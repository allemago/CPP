/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:34:28 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 12:22:22 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

class Brain
{
/*****************
*   PROTECTED    *
*****************/
protected:
    
    std::string _ideas[100];
    
/*****************
*     PUBLIC     *
*****************/
public:
	
	Brain();
	Brain(const std::string idea, const size_t i);
	Brain(const Brain& object);
	~Brain();

	Brain&	operator=(const Brain& object);

	void	setIdea(const std::string& idea, const size_t i);
};
