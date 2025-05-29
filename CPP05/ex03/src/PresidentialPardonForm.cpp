/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 14:33:20 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
                       : AForm("PresidentialPardonForm", 25, 5), _target("Link") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
                       : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object)
                       : AForm(object), _target(object._target) {}

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
		std::cout << _target << PARDONED << std::endl;
	}
	else
		std::cerr << _target << NOT_PARDONED << executor.getName() << " because: ", throw GradeTooLowException();
}
