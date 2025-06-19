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
void	PmergeMe<T>::mergeInsertSort(e_Mode mode, size_t n)
{
	if (mode == SORT_MAIN_MODE && n == _mainChain.size() / 2)
		return ;
	
	size_t size = _mainChain.size();
	size_t last = size - (size % 2);

	for (size_t i = 0; i < last; i++)
	{
		if (_mainChain[i] > _mainChain[i + 1])
		{
			switch (mode)
			{
				case EXTRACT_MIN_MODE:
					_pendingInserts.push_back(_mainChain[i + 1]);
					_mainChain.erase(_mainChain.begin() + (i + 1));
					break ;

				case SORT_MAIN_MODE:
					std::swap(_mainChain[i], _mainChain[i + 1]);
					break ;
			}
		}
	}

	if (mode == SORT_MAIN_MODE)
		mergeInsertSort(SORT_MAIN_MODE, n + 2);
}

template <typename T>
void	PmergeMe<T>::process()
{
	printBefore();

	if (_mainChain.size() > 1)
	{
		mergeInsertSort(EXTRACT_MIN_MODE, 0);
		mergeInsertSort(SORT_MAIN_MODE, 0);
	}

	// DEBUG
	std::cout << GREEN "\n\n_pendingInserts:" << std::endl;
	for (size_t i = 0; i < _pendingInserts.size(); i++)
		std::cout << _pendingInserts[i] << " ";
	std::cout << RESET << std::endl;
	// DEBUG
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << "Before:\t";
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain[i] << " ";
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	T c = obj.getContainer();
	
	os << "\nAfter:\t";
	for (size_t i = 0; i < c.size(); i++)
		os << c[i] << " ";
	os << "\nTime to process a range of\t" << c.size();
	os << " elements with " << obj.getContainerName();
	os << std::fixed << std::setprecision(5) << obj.getTime() << " us";

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

