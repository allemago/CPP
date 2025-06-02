/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:58:36 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 10:24:37 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

const std::string pseudoLiterals[6] = { "-inf", "+inf", "nan",
                                        "-inff", "+inff", "nanf" };

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

static e_Types	defineType(const std::string& literal)
{
	// pseudo-literals type
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; literal[j]; j++)
		{
			if (isspace(literal[j]))
				return (INVALID_TYPE);
		}
		if (literal == pseudoLiterals[i])
			return (PSEUDO_TYPE);
	}

	// char type
	if (isalpha(literal[0]) && !literal[1])
		return (CHAR_TYPE);

	// float, double, int types
	size_t hasDot = 0;
	size_t lastChar = literal.size() - 1;
	for (size_t i = 0; literal[i]; i++)
	{
		if (literal[i] == '.')
			hasDot++;
			
		if (i == 0
			&& ((literal[i] != '-' && literal[i] != '+' && !isdigit(literal[i]))
			|| ((literal[i] == '-' || literal[i] == '+') && !isdigit(literal[i + 1]))))
			return (INVALID_TYPE);
			
		if (hasDot > 1
			|| (i != lastChar && isalpha(literal[i]))
			|| (i == lastChar && literal[i] != 'f' && isalpha(literal[i])))
			return (INVALID_TYPE);
	}
	e_Types scalarType = INVALID_TYPE;
	if (hasDot && literal[lastChar] == 'f')
		scalarType = FLOAT_TYPE;
	else if (hasDot)
		scalarType = DOUBLE_TYPE;
	else if (!hasDot && !scalarType)
	{
		for (size_t i = 0; literal[i]; i++)
		{		
			if (i != 0 && !isdigit(literal[i]))
				return (INVALID_TYPE);
		}
		scalarType = INT_TYPE;
	}
	
	return (scalarType);
}

static bool	isOutOfRange(const double value, const e_Types scalarType)
{
	if ((scalarType == CHAR_TYPE || scalarType == INT_TYPE)
		&& (value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max()))
		return (true);
	
	if (scalarType == FLOAT_TYPE
		&& (value < -std::numeric_limits<float>::max()
			|| value > std::numeric_limits<float>::max()))
		return (true);
	
	if (scalarType == DOUBLE_TYPE
		&& (value < -std::numeric_limits<double>::max()
			|| value > std::numeric_limits<double>::max()))
		return (true);

	return (false);
}

static void	printType(const std::string& literal,
                  const e_Types scalarType,
                  const e_Types toPrint)
{
	double value = atof(literal.c_str());

	switch (toPrint)
	{
		case CHAR_TYPE:
			std::cout << "char -> ";
			(int)value >= 32 && (int)value <= 126 ?
				std::cout << static_cast<char>(value) : std::cout << NOT_DISPLAYABLE;
			std::cout << std::endl;
			break ;
		case INT_TYPE:
			std::cout << "int -> ";
			if (isOutOfRange(value, INT_TYPE))
				std::cout << NOT_DISPLAYABLE;
			else
			
			{
				scalarType == CHAR_TYPE ?
					std::cout << static_cast<int>(literal[0]) :
					std::cout << static_cast<int>(atof(literal.c_str()));
			}
			std::cout << std::endl;
			break ;
		case FLOAT_TYPE:
			std::cout << "float -> " << std::fixed << std::setprecision(1);
			scalarType == CHAR_TYPE ?
				std::cout << static_cast<float>(static_cast<int>(literal[0])) :
				std::cout << atof(literal.c_str());
			std::cout << "f" << std::endl;
			break ;
		case DOUBLE_TYPE:
			std::cout << "double -> " << std::fixed << std::setprecision(1);
			scalarType == CHAR_TYPE ?
				std::cout << static_cast<double>(static_cast<int>(literal[0])) :
				std::cout << static_cast<double>(atof(literal.c_str()));
			std::cout << std::endl;
			break ;
		default:
			break ;
	}
}

void	ScalarConverter::convert(const std::string& literal)
{
	e_Types scalarType;

	scalarType = defineType(literal);

	if (isOutOfRange(atof(literal.c_str()), scalarType))
		throw OutOfRangeException();		

	switch (scalarType)
	{
		case CHAR_TYPE:
			std::cout << "char -> " << literal << std::endl;
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
		case PSEUDO_TYPE:
			std::cout << "char -> " << NOT_DISPLAYABLE << std::endl;
			std::cout << "int -> " << NOT_DISPLAYABLE << std::endl;	
			std::cout << "float -> ";
			(literal == "-inf" || literal == "+inf" || literal == "nan") ?
				std::cout << (literal + "f") : std::cout << (literal);
			std::cout << std::endl << "double -> ";
			(literal == "-inff" || literal == "+inff" || literal == "nanf") ?
				std::cout << literal.substr(0, literal.size() - 1) : std::cout << literal;
			std::cout << std::endl;
			break ;
		default:
			throw InvalidFormatException();
			break ;
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
