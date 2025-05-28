/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:20:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 10:12:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Form.hpp"
# include <iostream>

# define GREEN "\e[1;32m"
# define RESET "\033[0m"

class Form;

class Bureaucrat
{
/*****************
*    PRIVATE     *
*****************/
private:

    std::string	_name;
	int			_grade;

/*****************
*     PUBLIC     *
*****************/
public:

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& object);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& object);

	const std::string&	getName() const;
	const int&			getGrade() const;
	Bureaucrat&			incrementGrade(); // _grade--
	Bureaucrat&			decrementGrade(); // _grade++
	void				signForm(Form& form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& object);
