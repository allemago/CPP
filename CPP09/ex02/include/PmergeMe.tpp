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
		else if (find(_mainChain.begin(), _mainChain.end(), nb) == _mainChain.end())
			_mainChain.push_back(nb);
		else
			throw std::runtime_error(ERR_DUP_VALUES);

		if (_mainChain.size() == MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}
}

template <typename T>
void	PmergeMe<T>::mergeInsertSort(size_t start, size_t end)
{
	if (end <= start)
		return ;
	
	size_t size = end - start + 1;
	size_t pairs = size / 2;
	bool isOdd = (size % 2 != 0);

	for (size_t i = 0; i < pairs; i++)
	{
		size_t first = start + 2 * i;
		size_t second = start + 2 * i + 1;
		if (_mainChain[first] < _mainChain[second])
			std::swap(_mainChain[first], _mainChain[second]);
	}

	for (size_t i = pairs; i > 0; i--)
	{
		size_t minIndex = start + 2 * (i - 1) + 1;
		int minValue = _mainChain[minIndex];
		_mainChain.erase(_mainChain.begin() + minIndex);
		_mainChain.insert(_mainChain.begin() + start + pairs, minValue);
	}

	int straggler;
	if (isOdd)
	{
		straggler = _mainChain[end];
		_mainChain.erase(_mainChain.begin() + end);
	}
	
	mergeInsertSort(start, start + pairs - 1);

	for (size_t i = 0; i < pairs; i++)
	{
		insertSorted(start, start + pairs - 1 + i, _mainChain[start + pairs + i]);
		_mainChain.erase(_mainChain.begin() + start + pairs + i + 1);
	}

	if (isOdd)
		insertSorted(start, end, straggler);
}

template <typename T>
void	PmergeMe<T>::insertSorted(size_t start, size_t end, int value)
{
	while (start <= end && _mainChain[start] < value)
		start++;
	_mainChain.insert(_mainChain.begin() + start, value);
}


template <typename T>
void	PmergeMe<T>::process()
{
	mergeInsertSort(0, _mainChain.size() - 1);
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << YELLOW "Before:\t" RESET;
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain[i] << " ";
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	double duration = obj.getTime();

	T c = obj.getContainer();
	
	os << YELLOW "\nAfter:\t" RESET;
	for (size_t i = 0; i < c.size(); i++)
		os << c[i] << " ";
	os << "\nTime to process a range of\t" << c.size();
	os << " elements with " << obj.getContainerName();
	os << std::fixed << std::setprecision(5) << duration << " us";

    return (os);
}

template <typename T>
double	PmergeMe<T>::getTime() const
{
	return (static_cast<double>(clock() - g_startTime) / CLOCKS_PER_SEC) * MICRO_SEC;
}

template <typename T>
const T&	PmergeMe<T>::getContainer() const
{
	return this->_mainChain;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerName() const
{
	return this->_type == VECTOR_TYPE ? "std::vector : " : "std::deque : ";
}

