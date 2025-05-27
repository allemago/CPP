/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:02:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/27 14:03:11 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main()
{
	{	
		std::cout << GREEN "TEST 1" RESET << std::endl;
		try
		{
			Bureaucrat a("a", 15);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			Bureaucrat b("b", 1);
			std::cout << b.getName() << ", bureaucrat grade " << b << "." << std::endl;
			Bureaucrat c("c", 151);
			std::cout << c.getName() << ", bureaucrat grade " << c << "." << std::endl;
			Bureaucrat d("d", 0);
			std::cout << d.getName() << ", bureaucrat grade " << d << "." << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
