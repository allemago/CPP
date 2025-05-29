/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:02:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 11:21:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main()
{
	{	
		std::cout << GREEN "TEST 1" RESET << std::endl;
		try
		{
			Bureaucrat a("Karen", 1);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			Form contract;
			Form lease("lease", 15, 15);
			a.signForm(contract);
			a.signForm(lease);
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
			Bureaucrat a("Karen", 1);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			Form contract;
			Form lease("lease", -15, 15);
			a.signForm(contract);
			a.signForm(lease);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{	
		std::cout << GREEN "TEST 3" RESET << std::endl;
		try
		{
			Bureaucrat a("Karen", 15);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			Form contract;
			Form lease("lease", 1, 1);
			a.signForm(contract);
			a.signForm(lease);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
