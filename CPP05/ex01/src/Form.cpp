/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:19:57 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/27 14:09:08 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form()
			:	_name("contract"),
				_isSigned(false),
				_minGradeToSign(1),
				_minGradeToExecute(1) {}

Form::Form(const std::string& name, const int& minGradeToSign, const int& minGradeToExecute)
			:	_name(name),
				_isSigned(false),
				_minGradeToSign(minGradeToSign),
				_minGradeToExecute(minGradeToExecute) {}

Form::Form(const Form& object)
			:	_name(object.getName()),
				_isSigned(object.getIsSigned()),
				_minGradeToSign(object.getMinGradeToSign()),
				_minGradeToExecute(object.getMinGradeToExecute()) {}

Form::~Form() {}

Form&	Form::operator=(const Form& object)
{
	(void)object;
	std::cout << ERR_ASSIGN_MSG << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& object)
{
    os << object.getName() << " " << ((object.getIsSigned() == true) ? " form is signed.\n" : " is not signed.\n");
	os << "Required grade to sign is " << object.getMinGradeToSign() << ".\n";
	os << "Required grade to execute is " << object.getMinGradeToExecute() << "." << std::endl;
    return (os);
}

const std::string& Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

const int&	Form::getMinGradeToSign() const
{
	return (this->_minGradeToSign);
}

const int&	Form::getMinGradeToExecute() const
{
	return (this->_minGradeToExecute);
}

void	Form::beSigned(const Bureaucrat& object)
{
	if (object.getGrade() <= getMinGradeToSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
