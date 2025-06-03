/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:42:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/03 14:08:03 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"

const std::string pseudoLiteralsFloat[3] = { "-inff", "+inff", "nanf" };
const std::string pseudoLiteralsDouble[3] = { "-inf", "+inf", "nan" };

bool	isInputValid(const int argc, const char* literal)
{
	if (argc != 2 || !literal[0])
		return (false);

	for (int i = 0; literal[i]; i++)
	{
		if (isspace(literal[i]))
		{
			std::cerr << INVALID_FORMAT << std::endl;
			return (false);
		}
	}
	
	return (true);
}

static e_Types	isPseudoLiteral(const std::string& literal)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (literal == pseudoLiteralsFloat[i])
			return (FLOAT_TYPE);
			
		else if (literal == pseudoLiteralsDouble[i])
			return (DOUBLE_TYPE);
	}
	
	return (INVALID_TYPE);
}

e_Types	defineType(const std::string& literal)
{
	e_Types scalarType = INVALID_TYPE;
	
	// pseudo-literals type
	if ((scalarType = isPseudoLiteral(literal)) != INVALID_TYPE)
		return (scalarType);

	// char type
	if (isprint(literal[0]) && !isdigit(literal[0]) && !literal[1])
		return (CHAR_TYPE);

	// float, double, int types
	size_t hasDot = 0;
	size_t lastChar = literal.size() - 1;
	bool hasOperator = false;
	for (size_t i = 0; literal[i]; i++)
	{
		if (literal[i] == '.')
		{
			if (isdigit(literal[i + 1]))
				hasDot++;
			else
				return (INVALID_TYPE);
				
			if (i == 0 || hasDot > 1)
				return (INVALID_TYPE);
		}

		else if (i == 0)
		{
			if (literal[i] == '-' || literal[i] == '+')
				hasOperator = true;
				
			if (((!hasOperator) && !isdigit(literal[i]))
				|| (hasOperator && !isdigit(literal[i + 1])))
				return (INVALID_TYPE);
		}

		else if (i == lastChar)
		{
			if (literal[i] != 'f' && !isdigit(literal[i]))
				return (INVALID_TYPE);
		}

		else if (!isdigit(literal[i]))
			return (INVALID_TYPE);
	}
	
	if (hasDot && literal[lastChar] == 'f')
		scalarType = FLOAT_TYPE;
	
	else if (hasDot)
		scalarType = DOUBLE_TYPE;
	
	else if (!hasDot && !scalarType)
	{
		for (size_t i = 0; literal[i]; i++)
		{
			if (i == 0 && hasOperator)
				continue;
				
			else if (!isdigit(literal[i]))
				return (INVALID_TYPE);
		}
		scalarType = INT_TYPE;
	}
	
	return (scalarType);
}

bool	isOutOfRange(const double value,
                     const e_Types scalarType,
					 const std::string& literal)
{
	if ((scalarType == CHAR_TYPE || scalarType == INT_TYPE)
		&& (value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max()))
		return (true);
	
	if (scalarType == FLOAT_TYPE
		&& (!isPseudoLiteral(literal))
		&& (value < -std::numeric_limits<float>::max()
			|| value > std::numeric_limits<float>::max()))
		return (true);
	
	if (scalarType == DOUBLE_TYPE
		&& (!isPseudoLiteral(literal))
		&& (value < -std::numeric_limits<double>::max()
			|| value > std::numeric_limits<double>::max()))
		return (true);

	return (false);
}

void	printType(const std::string& literal,
                  const e_Types scalarType,
                  const e_Types toPrint)
{
	double value = atof(literal.c_str());

	switch (toPrint)
	{
		case CHAR_TYPE:
			std::cout << "char: ";
			if (scalarType == CHAR_TYPE)
				std::cout << literal;
			else
			{
				(isPseudoLiteral(literal) || (int)value < 32 || (int)value > 126) ?
					std::cout << NOT_DISPLAYABLE : std::cout << static_cast<char>(value);
			}
			std::cout << std::endl;
			break ;
		case INT_TYPE:
			std::cout << "int: ";
			if (isPseudoLiteral(literal) || isOutOfRange(value, INT_TYPE, literal))
				std::cout << NOT_DISPLAYABLE;
			else
			{
				scalarType == CHAR_TYPE ?
					std::cout << static_cast<int>(literal[0]) :
					std::cout << static_cast<int>(value);
			}
			std::cout << std::endl;
			break ;
		case FLOAT_TYPE:
			std::cout << "float: " << std::fixed << std::setprecision(1);
			if (value < -std::numeric_limits<float>::max())
				std::cout << "-inf";
			else if (value > std::numeric_limits<float>::max())
				std::cout << "+inf";
			else
			{
				scalarType == CHAR_TYPE ?
					std::cout << static_cast<float>(literal[0]) :
					std::cout << value;
			}
			std::cout << "f" << std::endl;
			break ;
		case DOUBLE_TYPE:
			std::cout << "double: " << std::fixed << std::setprecision(1);
			if (value < -std::numeric_limits<double>::max())
				std::cout << "-inf";
			else if (value > std::numeric_limits<double>::max())
				std::cout << "+inf";
			else
			{
				scalarType == CHAR_TYPE ?
					std::cout << static_cast<double>(literal[0]) :
					std::cout << static_cast<double>(value);
			}
			std::cout << std::endl;
			break ;
		default:
			break ;
	}
}
