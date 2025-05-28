/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 11:36:04 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

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
		
	}
	else
		throw GradeTooLowException();
}
