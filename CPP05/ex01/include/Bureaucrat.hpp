/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:20:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 15:12:39 by magrabko         ###   ########.fr       */
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
//	==================== Canonical Form =========================

	Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat&);

//	==================== Custom Constructors ====================

	Bureaucrat(const std::string&, int);

//	==================== Getters / Setters =======================

	const std::string&	getName() const;
	const int&			getGrade() const;

//	==================== Public Methods =========================
	
	Bureaucrat&			incrementGrade(); // _grade--
	Bureaucrat&			decrementGrade(); // _grade++
	void				signForm(Form&);

//	==================== Exceptions =============================

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

std::ostream&   operator<<(std::ostream&, const Bureaucrat&);
