/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:41:59 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/01 15:02:05 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cctype>
# include <cfloat>
# include <limits>

# define INVALID_FORMAT "Error: invalid format"
# define OUT_OF_RANGE "Error: value out of range"
# define NOT_DISPLAYABLE "not displayable"

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

//	==================== Public Methods =========================

	static void	convert(const std::string&);	

//	==================== Exceptions =============================

	class InvalidFormatException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class OutOfRangeException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};
