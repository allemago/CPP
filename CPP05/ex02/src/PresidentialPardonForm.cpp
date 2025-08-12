/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 13:55:56 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
                       : AForm("PresidentialPardonForm", "Link", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object)
                       : AForm(object) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= getMinGradeToExecute())
		std::cout << getTarget() << PARDONED << std::endl;
	else
		std::cerr << getTarget() << NOT_PARDONED << executor.getName() << " because: ", throw GradeTooLowException();
}
