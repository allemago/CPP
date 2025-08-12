/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:19:57 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 13:19:21 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
			_name("Karen"),
			_grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
			_name(name),
			_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& object) : 
			_name(object.getName()),
			_grade(object.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& object)
{
    os << object.getGrade();
    return (os);
}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);	
}

const int&	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

Bureaucrat&	Bureaucrat::incrementGrade()
{
	(_grade - 1) < 1 ? throw GradeTooHighException() : _grade--;
	return (*this);
}

Bureaucrat&	Bureaucrat::decrementGrade()
{
	(_grade + 1) > 150 ? throw GradeTooLowException() : _grade++;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
