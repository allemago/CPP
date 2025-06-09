/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:30:17 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/09 13:28:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span() : _N(0) {}

Span::Span(size_t N)
{
	if (N > MAX_SIZE)
 		throw MaximumExceeded();
	_N = N;
}

Span::Span(const Span& object)
{
	*this = object;
}

Span::~Span() {}

Span&	Span::operator=(const Span& object)
{
	if (this != &object)
	{
		this->_N  = object._N;
		this->_values = object._values;
	}

	return (*this);
}

void	Span::addNumbers(long long value)
{
	if (value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		throw OutOfRange();

	if (_values.size() + 1 > _N)
		throw CapacityReached();
	
	_values.push_back(static_cast<int>(value));
	
	sort(_values.begin(), _values.end());
}

int	Span::shortestSpan()
{
	if (_values.size() <= 1)
		throw InsufficientValues();

	int result = _values[1] - _values[0];

	for (ITER it = _values.begin(); it != _values.end() - 1; ++it)
	{
		if (*(it + 1) - *it < result)
			result = *(it + 1) - *it;
	}

	return (result);
}

int	Span::longestSpan()
{
	if (_values.size() <= 1)
		throw InsufficientValues();
	
	int result = _values[1] - _values[0];

	for (ITER it = _values.begin(); it != _values.end() - 1; ++it)
	{
		if (*(it + 1) - *it > result)
			result = *(it + 1) - *it;
	}

	return (result);
}

const char* Span::MaximumExceeded::what() const throw()
{
	return (MAXIMUM_EXCEEDED);
}

const char* Span::OutOfRange::what() const throw()
{
	return (OUT_OF_RANGE);
}

const char* Span::CapacityReached::what() const throw()
{
	return (CAPACITY_REACHED);
}

const char* Span::InsufficientValues::what() const throw()
{
	return (INSUFFICIENT_VALUES);
}
