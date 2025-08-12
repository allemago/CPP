/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:19:57 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 13:55:38 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() :
			_name("form"),
			_target("target"),
			_isSigned(false),
			_minGradeToSign(1),
			_minGradeToExecute(1) {}

AForm::AForm(const std::string& name, const std::string& target, const int& minGradeToSign, const int& minGradeToExecute) :
			_name(name),
			_target(target),
			_isSigned(false),
			_minGradeToSign(minGradeToSign),
			_minGradeToExecute(minGradeToExecute)
{
	if (minGradeToSign < 1)
		std::cerr << "Minimum required to sign form: ", throw GradeTooHighException();
	else if (minGradeToSign > 150)
		std::cerr << "Minimum required to sign form: ", throw GradeTooLowException();

	if (minGradeToExecute < 1)
		std::cerr << "Minimum required to execute form: ", throw GradeTooHighException();
	else if (minGradeToExecute > 150)
		std::cerr << "Minimum required to execute form: ", throw GradeTooLowException();
}

AForm::AForm(const AForm& object) :
			_name(object.getName()),
			_target(object.getTarget()),
			_isSigned(object.getIsSigned()),
			_minGradeToSign(object.getMinGradeToSign()),
			_minGradeToExecute(object.getMinGradeToExecute()) {}

AForm::~AForm() {}

std::ostream&	operator<<(std::ostream& os, const AForm& object)
{
    os << object.getName() << " " << ((object.getIsSigned() == true) ? " form is signed.\n" : " is not signed.\n");
	os << "Required grade to sign is " << object.getMinGradeToSign() << ".\n";
	os << "Required grade to execute is " << object.getMinGradeToExecute() << "." << std::endl;
    return (os);
}

const std::string& AForm::getName() const
{
	return (this->_name);
}

const std::string& AForm::getTarget() const
{
	return (this->_target);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

const int&	AForm::getMinGradeToSign() const
{
	return (this->_minGradeToSign);
}

const int&	AForm::getMinGradeToExecute() const
{
	return (this->_minGradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& object)
{
	if (object.getGrade() <= getMinGradeToSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
