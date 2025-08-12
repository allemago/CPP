/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:02:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:07:01 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int	main()
{
	{	
		std::cout << GREEN "TEST 1" RESET << std::endl;
		try
		{
			Bureaucrat a("Martin", 1);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			ShrubberyCreationForm form;
			a.executeForm(form);
			for (int i = 0; i < 137; i++)
				a.decrementGrade();
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			a.executeForm(form);
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
			std::srand(std::time(NULL));
			Bureaucrat a("Karen", 1);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			RobotomyRequestForm form;
			a.executeForm(form);
			for (int i = 0; i < 45; i++)
				a.decrementGrade();
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			a.executeForm(form);
			
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
			Bureaucrat a("Anne", 1);
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			PresidentialPardonForm form;
			a.executeForm(form);
			for (int i = 0; i < 5; i++)
				a.decrementGrade();
			std::cout << a.getName() << ", bureaucrat grade " << a << "." << std::endl;
			a.executeForm(form);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	return (0);
}
