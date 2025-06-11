#include "../include/Span.hpp"

bool isSorted = false;

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

void	Span::addNumber(long long value)
{
	if (value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		throw OutOfRange();

	if (_values.size() + 1 > _N)
		throw CapacityReached();
	
	_values.push_back(static_cast<int>(value));

	isSorted = false;
}

long long	Span::shortestSpan()
{
	if (_values.size() <= 1)
		throw InsufficientValues();
	
	if (!isSorted)
	{
		sort(_values.begin(), _values.end());
		isSorted = true;
	}

	std::vector<int> result(_values.size());
	
	std::adjacent_difference(_values.begin(), _values.end(), result.begin());

	return (*std::min_element(result.begin() + 1, result.end()));
}

long long	Span::longestSpan()
{
	if (_values.size() <= 1)
		throw InsufficientValues();

	return (getMax() - getMin());
}

long long	Span::getMin() const
{
	return (*std::min_element(_values.begin(), _values.end()));
}

long long	Span::getMax() const
{
	return (*std::max_element(_values.begin(), _values.end()));
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
