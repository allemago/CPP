/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:41:59 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 15:50:54 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Utils.hpp"
# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>

class ScalarConverter
{
/*****************
*    PRIVATE     *
*****************/
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	ScalarConverter&	operator=(const ScalarConverter&);

/*****************
*     PUBLIC     *
*****************/
public:

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
