/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:41:59 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/31 20:00:29 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cctype>

# define NOT_DISPLAYABLE_MSG ": invalid format."
# define ALL_SPACES " \t\n\v\f\r"

enum e_Types
{
	INVALID_TYPE = 0,
	CHAR_TYPE = 1,
	INT_TYPE = 2,
	FLOAT_TYPE = 3,
	DOUBLE_TYPE = 4,
	PSEUDO_TYPE = 5
};

class ScalarConverter
{
/*****************
*    PRIVATE     *
*****************/
private:

	ScalarConverter();

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter&	operator=(const ScalarConverter&);

//	==================== Custom Constructors ====================

//	==================== Public Methods =========================

	static void	convert(const std::string&);	

//	==================== Exceptions =============================

	class NotDisplayableException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};
