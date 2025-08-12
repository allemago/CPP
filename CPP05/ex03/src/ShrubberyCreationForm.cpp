/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:13 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:15:24 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
                      : AForm("ShrubberyCreationForm", "Cocoyashi", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
                      : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object)
                      : AForm(object) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= getMinGradeToExecute())
	{
		std::string	fileName = executor.getName() + "_shrubbery";
		std::ofstream file(fileName.c_str());
		if (!file)
			std::cerr << fileName << ERR_OPEN_FILE << std::endl;
		else
			file << ASCII_TREES, std::cout <<  PLANT_TREES << getTarget() << std::endl;
		file.close();
	}
	else
		std::cerr << executor.getName() << TREES_NOT_PLANTED, throw GradeTooLowException();
}
