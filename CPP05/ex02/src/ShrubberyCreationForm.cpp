/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:13 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 15:10:39 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
                      : AForm("ShrubberyCreation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object)
                      : AForm(object) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& object)
{
	AForm::operator=(object);
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= getMinGradeToExecute())
	{
		std::ofstream file(executor.getName() + "_shrubbery");
		if (!file)
			std::cerr << executor.getName() + "_shrubbery: " << ERR_OPEN_FILE << std::endl;
		else
			file << ASCII_TREES;
	}
	else
		std::cerr << executor.getName() << JOB_NOT_DONE, throw GradeTooLowException();
}
