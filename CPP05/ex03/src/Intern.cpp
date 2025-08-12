/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:55:43 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:46:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

std::string forms[3] = {	"presidential pardon",
							"robotomy request",
							"shrubbery creation"	};

Intern::Intern() {}

Intern::~Intern() {}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates ";
			switch (i)
			{
				case 0:
					std::cout << "PresidentialPardonForm" << std::endl;
					return (new PresidentialPardonForm(target));
				case 1:
					std::cout << "RobotomyRequestForm" << std::endl;
					return (new RobotomyRequestForm(target));
				case 2:
					std::cout << "ShrubberyCreationForm" << std::endl;
					return (new ShrubberyCreationForm(target));
			}
		}
	}

	std::cerr << name;
	throw UnknownType();
	
	return NULL;
}

const char* Intern::UnknownType::what() const throw()
{
	return (": type of form does not exist");
}
