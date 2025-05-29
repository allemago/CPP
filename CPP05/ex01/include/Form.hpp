/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:58:50 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 15:13:55 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <iostream>

# define GREEN "\e[1;32m"
# define RESET "\033[0m"
# define ERR_ASSIGN_MSG "Assignment operator called on object with const members: assignment is not allowed."

class Bureaucrat;

class Form
{
/*****************
*    PRIVATE     *
*****************/
private:

    const std::string	_name;
	bool				_isSigned;
	const int			_minGradeToSign;
	const int			_minGradeToExecute;

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	Form();
	Form(const Form&);
	~Form();
	Form&	operator=(const Form&);

//	==================== Custom Constructors ====================

	Form(const std::string&, const int&, const int&);

//	==================== Getters / Setters ======================

	const std::string&	getName() const;
	bool				getIsSigned() const;
	const int&			getMinGradeToSign() const;
	const int&			getMinGradeToExecute() const;
	
//	==================== Public Methods =========================

	void				beSigned(const Bureaucrat&);

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

std::ostream&   operator<<(std::ostream&, const Form&);
