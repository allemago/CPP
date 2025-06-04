/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:21:42 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/04 15:33:52 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>

# define BOLD "\033[1m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"
# define OUT_OF_BOUNDS "Error: index is out of bounds."

template <typename T>
class Array
{
/*****************
*    PRIVATE     *
*****************/
private:

	size_t	_n;
	T*		_array;

/*****************
*     PUBLIC     *
*****************/
public:

//	==================== Canonical Form =========================

	Array();
	Array(const Array<T>&);
	~Array();
	Array<T>&	operator=(const Array<T>&);

//	==================== Custom Constructors ====================

	Array(size_t);

// ============== Additional Operator Overloads =================

	T&	operator[](size_t) const;
	
//	==================== Public Methods =========================

	size_t	size() const;
	
//	==================== Exceptions =============================

	class indexOutOfBounds: public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

# include "Array.tpp"
