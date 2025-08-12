/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:10 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:14:59 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
                    : AForm("RobotomyRequestForm", "Zelda", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
                    : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object)
                    : AForm(object) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= getMinGradeToExecute())
	{
		if ((std::rand() / (double)RAND_MAX) < 0.5)
			std::cout << "Bzzzz... " << getTarget() << ROBOTOMY_SUCCESS << std::endl;
		else
			std::cout << ROBOTOMY_FAILED << getTarget() << std::endl;
		
	}
	else
	{
		std::cerr << executor.getName() << " couldn't robotomized ";
		std::cerr << getTarget() << " because: ", throw GradeTooLowException();
		
	}
}
