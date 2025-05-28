/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 11:10:43 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>
# include <fstream>

#define ASCII_TREES "               ,@@@@@@@,						\n" \
                    "       ,,,.   ,@@@@@@/@@,  .oo8888o.			\n" \
                    "    ,&&&%&%&&%,@@@@@/@@@@@@,8888\\88/8o		\n" \
                    "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'		\n" \
                    "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'		\n" \
                    "   %&&%/ %&&&&&@@\\ V /@@' `88\\8 `/88'		\n" \
                    "   `&%\\ ` /%&'    |.|        \\ '|8'			\n" \
                    "       |o|        | |         | |				\n" \
                    "       |.|        | |         | |				\n" \
                    "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"


class ShrubberyCreationForm : public AForm
{
/*****************
*     PUBLIC     *
*****************/
public:

//	==================== Canonical Form =========================

	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

//	==================== Public Methods =========================

	virtual void	execute(const Bureaucrat&) const;
};
