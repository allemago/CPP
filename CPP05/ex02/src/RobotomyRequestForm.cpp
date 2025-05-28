/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:10 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 15:18:05 by magrabko         ###   ########.fr       */
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
		if (std::rand() % 2 == 0)
			std::cout << "Bzzzz... " << executor.getName() << ROBOTOMY_SUCCESS << std::endl;
		else
			std::cerr << ROBOTOMY_FAILED << executor.getName() << std::endl;
		
	}
	else
		std::cerr << ROBOTOMY_FAILED << executor.getName() << ": ", throw GradeTooLowException();
}
