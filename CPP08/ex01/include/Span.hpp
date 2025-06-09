/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:30:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/09 17:43:45 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <numeric>
# include <iterator>
# include <algorithm>
# include <exception>
# include <vector>
# include <limits>


# define BOLD "\033[1m"
# define RESET "\033[0m"

# define MAX_SIZE 50000

# define INSUFFICIENT_VALUES "NA\nCannot compute span: insufficient number of values."
# define MAXIMUM_EXCEEDED "Capacity limit exceeded: please choose a smaller size."
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

	void		addNumber(long long);
	long long	shortestSpan();
	long long	longestSpan();

//	==================== Getters / Setters ======================

	long long	getMin() const;
	long long	getMax() const;

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
