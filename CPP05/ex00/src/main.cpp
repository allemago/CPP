/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:02:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 19:32:07 by magrabko         ###   ########.fr       */
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
			std::cout << a.getName() << " grade is " << a << std::endl;
			Bureaucrat b("b", 1);
			std::cout << b.getName() << " grade is " << b << std::endl;
			Bureaucrat c("c", 155);
			std::cout << c.getName() << " grade is " << c << std::endl;
			Bureaucrat d("d", 0);
			std::cout << d.getName() << " grade is " << d << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{	
		std::cout << GREEN "TEST 2" RESET << std::endl;
		try
		{
			Bureaucrat a("a", 1);
			std::cout << a.getName() << " grade is " << a << std::endl;
			for (int i = 0; i < 9; i++)
				a.decrementGrade();
			std::cout << a.getName() << " grade is " << a << std::endl;
			for (int i = 0; i < 10; i++)
				a.incrementGrade();
			std::cout << a.getName() << " grade is " << a << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
