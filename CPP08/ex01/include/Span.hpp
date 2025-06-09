/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:30:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/09 13:17:28 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <limits>

# define MAX_SIZE 100000
# define ITER std::vector<int>::iterator

# define INSUFFICIENT_VALUES "NA\nCannot compute span: insufficient number of values."
# define MAXIMUM_EXCEEDED "Capacity limit exceeded. Please choose a smaller size."
# define CAPACITY_REACHED "Cannot add value: maximum capacity reached."
# define OUT_OF_RANGE "Value is out of range."

class Span
{
/*****************
*    PRIVATE     *
*****************/
private:

	size_t				_N;
	std::vector<int>	_values;

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	Span();
	Span(const Span&);
	~Span();
	Span&	operator=(const Span&);

//	==================== Custom Constructors ====================

	Span(size_t);

//	==================== Public Methods =========================

	void	addNumbers(long long);
	int		shortestSpan();
	int		longestSpan();

//	==================== Exceptions =============================

	class  MaximumExceeded: public std::exception
	{
		public:
			const char* what() const throw();
	};
		
	class  OutOfRange: public std::exception
	{
		public:
			const char* what() const throw();
	};

	class CapacityReached : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class  InsufficientValues: public std::exception
	{
		public:
			const char* what() const throw();
	};

};
