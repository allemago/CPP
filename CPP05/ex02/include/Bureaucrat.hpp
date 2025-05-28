/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:20:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 10:53:51 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>

# define GREEN "\e[1;32m"
# define RESET "\033[0m"

class AForm;

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

//	==================== Getters / Setters ======================

	const std::string&	getName() const;
	const int&			getGrade() const;

//	==================== Public Methods =========================

	Bureaucrat&			incrementGrade(); // _grade--
	Bureaucrat&			decrementGrade(); // _grade++
	void				signForm(AForm&);
	void				executeForm(const AForm&) const;

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
