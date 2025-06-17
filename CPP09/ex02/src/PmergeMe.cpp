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
	if (_rawSequence.empty() || !isSequenceValid())
		throw std::runtime_error(USAGE);	
}

bool	PmergeMe::isSequenceValid()
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
			return false;
		else
			_d.push_back(nb);
	}

    return true;
}



std::ostream&   operator<<(std::ostream& os, const PmergeMe& object)
{
	(void)object;
	os << "Before:\t";
	for (std::vector<int>::iterator it = getDeque(DEQUE_TYPE).begin(); )
	os << "\n";
	os << "After:\t";
    return (os);
}
