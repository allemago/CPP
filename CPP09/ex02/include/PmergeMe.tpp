#include "../include/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : _rawSequence("") { parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const std::string& raw) : _rawSequence(raw) { parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>&	PmergeMe<T>::operator=(const PmergeMe<T>& obj)
{
	if (this != &obj)
	{
		_rawSequence = obj._rawSequence;

		if (_sequence.size())
			_sequence.clear();
		_sequence = obj._sequence;

		if (_mainChain.size())
			_mainChain.clear();
		_mainChain = obj._mainChain;
	}
	return *this;
}

template <typename T>
bool	PmergeMe<T>::isSequenceEmpty() const
{
	return _rawSequence.find_first_not_of(WHITESPACE) == std::string::npos;
}

template <typename T>
void	PmergeMe<T>::parseSequence()
{
	if (isSequenceEmpty())
		throw std::runtime_error(USAGE);

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
		else if (find(_sequence.begin(), _sequence.end(), nb) == _sequence.end())
			_sequence.push_back(nb);
		else
			throw std::runtime_error(ERR_DUP_VALUES);

		if (_sequence.size() == MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}
}

template <typename T>
void	PmergeMe<T>::sort(size_t pairs)
{
	size_t size = _sequence.size();

	if (pairs == size / 2)
		return ;

	size % 2 != 0 ? _oddFlag.isOdd = true : _oddFlag.isOdd = false;
	if (_oddFlag.isOdd)
	{
		_oddFlag.straggler = _sequence.back();
		_sequence.pop_back();
	}

	size_t end = size - pairs;
	for (size_t i = 0; i < end; i+=2)
	{
		if (_sequence[i] > _sequence[i + 1])
			;
	}
}

template <typename T>
void	PmergeMe<T>::process()
{
	if (_sequence.size() > 1)
	{
		sort(1);
	}
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	double duration = obj.getDuration();

	T c1 = obj.getContainer(SEQUENCE);

	os << YELLOW "Before:\t" RESET;
	size_t size = c1.size();
	for (size_t i = 0; i < size; i++)
		os << c1[i] << (i + 1 != size ? " " : "\n");

	T c2 = obj.getContainer(MAINCHAIN);
	
	os << YELLOW "After:\t" RESET;
	size = c2.size();
	for (size_t i = 0; i < size; i++)
		os << c2[i] << (i + 1 != size ? " " : "\n");
	os << "\nTime to process a range of\t" << size;
	os << " elements with " << obj.getContainerType() << " : ";
	os << std::fixed << std::setprecision(5) << duration << " us";

    return (os);
}

template <typename T>
double	PmergeMe<T>::getDuration() const
{
	return (static_cast<double>(clock() - g_startTime) / CLOCKS_PER_SEC) * MICRO_SEC;
}

template <typename T>
const T&	PmergeMe<T>::getContainer(e_Name name) const
{
	return name == SEQUENCE ? this->_sequence : this->_mainChain;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerType() const
{
	return this->_type == VECTOR_TYPE ? "std::vector" : "std::deque";
}

