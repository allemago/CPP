/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:10 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 11:41:05 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
                    : AForm("RobotomyRequest", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object)
                    : AForm(object) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& object)
{
	AForm::operator=(object);
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= getMinGradeToExecute())
	{
		
	}
	else
		std::cerr << executor.getName() << " couldn't be robotomized because: ", throw GradeTooLowException();
}
