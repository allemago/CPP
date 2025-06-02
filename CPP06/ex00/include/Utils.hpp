/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:43:31 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 15:00:49 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <cfloat>
#include <limits>

# define USAGE "Usage: ./convert <literal>"
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
};

e_Types	defineType(const std::string&);
bool	isInputValid(const int, const std::string&);
bool	isOutOfRange(const double, const e_Types, const std::string&);
void	printType(const std::string&, const e_Types, const e_Types);