/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:02:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:56:06 by magrabko         ###   ########.fr       */
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
		AForm* rrf = NULL;
		try
		{
			Intern a;
			Bureaucrat b("Karen", 1);

			rrf = a.makeForm("presidential pardon", "Zelda");

			b.executeForm(*rrf);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
		std::cout << std::endl;
	}
	{	
		std::cout << GREEN "TEST 2" RESET << std::endl;
		AForm* rrf = NULL;
		try
		{
			Intern a;
			Bureaucrat b("Anne", 1);

			rrf = a.makeForm("robotomy request", "Link");

			b.executeForm(*rrf);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
		std::cout << std::endl;
	}
	{	
		std::cout << GREEN "TEST 3" RESET << std::endl;
		AForm* rrf = NULL;
		try
		{
			Intern a;
			Bureaucrat b("Tom", 1);

			rrf = a.makeForm("shrubbery creation", "Cocoyashi");

			b.executeForm(*rrf);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
		std::cout << std::endl;
	}
		{	
		std::cout << GREEN "TEST 4" RESET << std::endl;
		try
		{
			Intern a;
			AForm* rrf;

			rrf = a.makeForm("blabla", "Random");
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
