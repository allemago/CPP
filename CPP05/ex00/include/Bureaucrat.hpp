/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:20:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 13:05:54 by magrabko         ###   ########.fr       */
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

    const std::string	_name;
	int					_grade; // 1 (highest) to 150 (lowest)

	Bureaucrat&	operator=(const Bureaucrat&);
	
	/*****************
	 *     PUBLIC     *
	 *****************/
	public:
	
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();

//	==================== Public Methods =========================

	Bureaucrat&			incrementGrade(); // _grade--
	Bureaucrat&			decrementGrade(); // _grade++

	const std::string&	getName() const;
	const int&			getGrade() const;
	
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
