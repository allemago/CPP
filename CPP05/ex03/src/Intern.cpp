/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:55:43 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 15:06:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

std::string forms[3] = {	"presidential pardon",
							"robotomy request",
							"shrubbery creation"	};

Intern::Intern() {}

Intern::Intern(const Intern& object)
{
	*this = object;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& object)
{
	(void)object;
	return (*this);
}

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
	
	std::cerr << name << ": type of form does not exist" << std::endl;
	return (NULL);
}
