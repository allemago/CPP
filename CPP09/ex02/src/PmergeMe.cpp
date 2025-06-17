#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() : _rawSequence("") { init(); }

PmergeMe::PmergeMe(const std::string& raw) : _rawSequence(raw) { init(); }

PmergeMe::PmergeMe(const PmergeMe& object)
{
	*this = object;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& object)
{
	if (this != &object)
	{

	}
	return *this;
}

void	PmergeMe::init()
{
	if (_rawSequence.empty()
		|| _rawSequence.find_first_not_of(WHITESPACE) == std::string::npos)
		throw std::runtime_error(USAGE);

	parseSequence();
}

void	PmergeMe::parseSequence()
{
	std::istringstream issSeq(_rawSequence);
	std::string token;
    long long nb;
	
	while (issSeq >> token)
	{
		std::istringstream issToken(token);
		if (!(issToken >> nb)
			|| !issToken.eof()
			|| nb < 0
			|| nb > std::numeric_limits<int>::max())
			throw std::runtime_error(USAGE);
		else
			_d.push_back(nb);

		if (_d.size() == MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}
}

void	PmergeMe::mergeInsert()
{
	bool isOdd = true;
	int last;
	if (distance(_d.begin(), _d.end()) % 2 == 0)
		isOdd = false;
	else
	{ last = _d.back(); _d.pop_back(); }

	for (std::deque<int>::iterator it = _d.begin(); distance(_d.begin(), _d.end()) >= 2;)
	{
		it = _d.begin();
		*it < *(it + 1) ?
		  _v.push_back(std::make_pair(*it, *(it + 1)))
		: _v.push_back(std::make_pair(*(it + 1), *it));
		_d.erase(it);
		_d.erase(it + 1);
	}
	if (isOdd)
		_d.push_back(last);
}

void	PmergeMe::process()
{
	printBefore();

	if (distance(_d.begin(), _d.end()) > 2)
	{
		mergeInsert();
	}
}

void	PmergeMe::printBefore() const
{
	std::cout << "Before:\t";
	for (std::deque<int>::const_iterator it = _d.begin(); it != _d.end(); ++it)
		std::cout << *it << " ";
}

std::ostream&   operator<<(std::ostream& os, const PmergeMe& object)
{
	os << "\nAfter:\t";
	for (std::vector< std::pair<int, int> >::const_iterator it = object.getV().begin(); it != object.getV().end(); ++it)
		os << it->first << " " << it->second << " ";
	os << "\nTime to process a range of\t" << std::distance(object.getD().begin(), object.getD().end());
	os << " elements with std::deque : ";
	os << std::fixed << std::setprecision(5) << object.getTime() << " us\n";

	os << "Time to process a range of\t" << std::distance(object.getV().begin(), object.getV().end());
	os << " elements with std::vector : ";
	os << std::fixed << std::setprecision(5) << object.getTime() << " us";
    return (os);
}

const std::deque<int>&	PmergeMe::getD() const { return _d; }

const std::vector< std::pair<int, int> >&	PmergeMe::getV() const { return _v; }

float	PmergeMe::getTime() const
{
	time_t now;
	time(&now);
	float duration = difftime(now, g_startTime);

	return duration * MICRO_SEC;
}
