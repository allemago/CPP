/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:58:50 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:53:35 by magrabko         ###   ########.fr       */
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
/****************
*    PRIVATE    *
*****************/
private:

    const std::string	_name;
    const std::string	_target;
	bool				_isSigned;
	const int			_minGradeToSign;
	const int			_minGradeToExecute;
	
	AForm&	operator=(const AForm&);

/****************
*    PUBLIC     *
*****************/
public:

	AForm();
	AForm(const std::string&, const std::string&, const int&, const int&);
	AForm(const AForm&);
	virtual ~AForm();

//	==================== Public Methods =========================

	void				beSigned(const Bureaucrat&);

	const std::string&	getName() const;
	const std::string&	getTarget() const;
	bool				getIsSigned() const;
	const int&			getMinGradeToSign() const;
	const int&			getMinGradeToExecute() const;

	virtual void		execute(const Bureaucrat&) const = 0;

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

std::ostream&   operator<<(std::ostream&, const AForm&);
