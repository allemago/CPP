/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:58:50 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/27 19:32:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <iostream>

# define GREEN "\e[1;32m"
# define RESET "\033[0m"
# define ERR_ASSIGN_MSG "Assignment operator called on object with const members: assignment is not allowed."

class Bureaucrat;

class AForm
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

	AForm();
	AForm(const std::string& name, const int& minGradeToSign, const int& minGradeToExecute);
	AForm(const AForm& object);
	~AForm();

	AForm&	operator=(const AForm& object);

	const std::string&	getName() const;
	bool				getIsSigned() const;
	const int&			getMinGradeToSign() const;
	const int&			getMinGradeToExecute() const;
	void				beSigned(const Bureaucrat& object);

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

std::ostream&   operator<<(std::ostream& os, const AForm& object);
