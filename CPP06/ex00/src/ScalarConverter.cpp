/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:58:36 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/31 23:23:38 by magrabko         ###   ########.fr       */
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

static bool	isInSet(const std::string& literal, const std::string& set)
{
	for (int i = 0; literal[i]; i++)
	{
		for (int j = 0; set[j]; j++)
		{
			if (literal[i] == set[j])
				return (true);
		}
	}
	return (false);
}

static e_Types	defineType(const std::string& literal)
{		
	for (int i = 0; i < 6; i++)
	{
		if (literal == pseudoLiterals[i])
			return (PSEUDO_TYPE);
	}

	if (isalpha(literal[0]) && !literal[1])
		return (CHAR_TYPE);

	if (isInSet(literal, ALL_SPACES) ||
		(literal[literal.size() - 1] == 'f' &&
		isInSet(literal.substr(0, literal.size() - 1), "f")))
		return (INVALID_TYPE);

	int hasDot = 0;
	for (size_t i = 0; i < literal.size() - 1; i++)
	{
		if (literal[i] == '.')
			hasDot++;
		if (hasDot > 1 || (hasDot && isalpha(literal[i])))
			return (INVALID_TYPE);
	}
	e_Types scalarType = INVALID_TYPE;
	(hasDot && literal[literal.size() - 1] == 'f') ?
		scalarType = FLOAT_TYPE : scalarType = DOUBLE_TYPE;
	
	if (!hasDot && scalarType == DOUBLE_TYPE)
	{
		for (int i = 0; literal[i]; i++)
		{
			if (i == 0 && (literal[i] == '-' || literal[i] == '+')
				&& !isdigit(literal[i + 1]))
				return (INVALID_TYPE);
						
			if (i != 0 && !isdigit(literal[i]))
				return (INVALID_TYPE);
		}
		scalarType = INT_TYPE;
	}
	
	return (scalarType);
}

void	printType(const std::string& literal,
                  const e_Types scalarType,
                  const e_Types toPrint)
{
	switch (toPrint)
	{
		case CHAR_TYPE:
		{
			double value = atof(literal.c_str());
			char c = static_cast<char>(value);
			std::cout << "char -> ";
			isprint(static_cast<int>(value)) ?
				std::cout << c : std::cout << NOT_DISPLAYABLE;
			std::cout << std::endl;
			break ;
		}
		case INT_TYPE:
			std::cout << "int -> ";
			scalarType == CHAR_TYPE ?
				std::cout << static_cast<int>(literal[0]) :
				std::cout << static_cast<int>(atof(literal.c_str()));
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
			std::cout << "double -> ";
			(literal == "-inff" || literal == "+inff" || literal == "nanf") ?
				std::cout << literal.substr(0, literal.size() - 1) : std::cout << literal;
			std::cout << std::endl;
			break ;
		default:
			std::cerr << literal, throw InvalidFormatException();
			break ;
	}
}

const char* ScalarConverter::InvalidFormatException::what() const throw()
{
	return (INVALID_FORMAT);
}
