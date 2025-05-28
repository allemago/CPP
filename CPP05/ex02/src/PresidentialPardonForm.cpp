/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 15:25:12 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
                       : AForm("PresidentialPardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& object)
{
	AForm::operator=(object);
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= getMinGradeToExecute())
	{
		std::cout << executor.getName() << PARDON << std::endl;
	}
	else
		std::cerr << executor.getName() << NO_PARDON, throw GradeTooLowException();
}
