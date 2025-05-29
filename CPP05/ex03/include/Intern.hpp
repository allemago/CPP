/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:56:12 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 14:29:20 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	Intern();
	Intern(const Intern&);
	~Intern();
	Intern&	operator=(const Intern&);

//	==================== Public Methods =========================

	AForm*	makeForm(const std::string& name, const std::string& target);
	
};
