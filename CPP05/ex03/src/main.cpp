/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:02:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 15:00:29 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int	main()
{
	{	
		std::cout << GREEN "TEST 1" RESET << std::endl;
		try
		{
			Intern a;
			AForm* rrf;

			rrf = a.makeForm("presidential pardon", "Zelda");

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
			Intern a;
			AForm* rrf;

			rrf = a.makeForm("robotomy request", "Link");

			
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
			Intern a;
			AForm* rrf;

			rrf = a.makeForm("shrubbery creation", "Cocoyashi");
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
		{	
		std::cout << GREEN "TEST 4" RESET << std::endl;
		try
		{
			Intern a;
			AForm* rrf;

			rrf = a.makeForm("unknown request", "Random");
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
