/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:58:36 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 12:49:38 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& object)
{
	*this = object;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& object)
{
	(void)object;
	return (*this);
}

void	ScalarConverter::convert(const std::string& literal)
{
	e_Types scalarType;

	scalarType = defineType(literal);

	if (isOutOfRange(atof(literal.c_str()), scalarType, literal))
		throw OutOfRangeException();		

	switch (scalarType)
	{
		case CHAR_TYPE:
			printType(literal, scalarType, CHAR_TYPE);
			printType(literal, scalarType, INT_TYPE);
			printType(literal, scalarType, FLOAT_TYPE);
			printType(literal, scalarType, DOUBLE_TYPE);
			break ;
		case INT_TYPE:
			printType(literal, scalarType, CHAR_TYPE);
			printType(literal, scalarType, INT_TYPE);
			printType(literal, scalarType, FLOAT_TYPE);
			printType(literal, scalarType, DOUBLE_TYPE);
			break ;
		case FLOAT_TYPE:
			printType(literal, scalarType, CHAR_TYPE);
			printType(literal, scalarType, INT_TYPE);
			printType(literal, scalarType, FLOAT_TYPE);
			printType(literal, scalarType, DOUBLE_TYPE);
			break ;
		case DOUBLE_TYPE:
			printType(literal, scalarType, CHAR_TYPE);
			printType(literal, scalarType, INT_TYPE);
			printType(literal, scalarType, FLOAT_TYPE);
			printType(literal, scalarType, DOUBLE_TYPE);
			break ;
		default:
			throw InvalidFormatException();
	}
}

const char* ScalarConverter::InvalidFormatException::what() const throw()
{
	return (INVALID_FORMAT);
}

const char* ScalarConverter::OutOfRangeException::what() const throw()
{
	return (OUT_OF_RANGE);
}
