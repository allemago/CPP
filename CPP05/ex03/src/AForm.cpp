/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:19:57 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 14:47:06 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm()
			:	_name("form"),
				_isSigned(false),
				_minGradeToSign(1),
				_minGradeToExecute(1) {}

AForm::AForm(const std::string& name, const int& minGradeToSign, const int& minGradeToExecute)
			:	_name(name),
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

AForm::AForm(const AForm& object)
			:	_name(object.getName()),
				_isSigned(object.getIsSigned()),
				_minGradeToSign(object.getMinGradeToSign()),
				_minGradeToExecute(object.getMinGradeToExecute()) {}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& object)
{
	(void)object;
	std::cout << ERR_ASSIGN_MSG << std::endl;
	return (*this);
}

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
