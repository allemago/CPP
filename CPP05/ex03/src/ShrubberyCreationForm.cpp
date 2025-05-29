/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:13 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 14:34:15 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
                      : AForm("ShrubberyCreationForm", 145, 137), _target("Cocoyashi") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
                      : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object)
                      : AForm(object), _target(object._target) {}

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
		std::string	fileName = executor.getName() + "_shrubbery";
		std::ofstream file(fileName.c_str());
		if (!file)
			std::cerr << fileName << ERR_OPEN_FILE << std::endl;
		else
			file << ASCII_TREES, std::cout <<  PLANT_TREES << _target << std::endl;
		file.close();
	}
	else
		std::cerr << executor.getName() << TREES_NOT_PLANTED, throw GradeTooLowException();
}
