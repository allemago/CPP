/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:10 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 14:33:49 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
                    : AForm("RobotomyRequestForm", 72, 45), _target("Zelda") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
                    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object)
                    : AForm(object), _target(object._target) {}

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
		if ((std::rand() / (double)RAND_MAX) < 0.5)
			std::cout << "Bzzzz... " << _target << ROBOTOMY_SUCCESS << std::endl;
		else
			std::cout << ROBOTOMY_FAILED << _target << std::endl;
		
	}
	else
	{
		std::cerr << executor.getName() << " couldn't robotomized ";
		std::cerr << _target << " because: ", throw GradeTooLowException();
		
	}
}
