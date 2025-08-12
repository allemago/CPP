/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:56:12 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 14:46:45 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{

/*****************
*    PRIVATE     *
*****************/
private:

	Intern(const Intern&);
	Intern&	operator=(const Intern&);

/*****************
*     PUBLIC     *
*****************/
public:

	Intern();
	~Intern();

//	==================== Public Methods =========================

	AForm*	makeForm(const std::string& name, const std::string& target);
	
//	==================== Exceptions =============================

	class UnknownType : public std::exception
	{
		public:
			const char* what() const throw();
	};
};
