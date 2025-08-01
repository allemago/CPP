/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:20:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 15:10:44 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define GREEN "\e[1;32m"
# define RESET "\033[0m"

class Bureaucrat
{
/*****************
*    PRIVATE     *
*****************/
private:

    std::string	_name;
	int			_grade; // 1 (highest) to 150 (lowest)

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
