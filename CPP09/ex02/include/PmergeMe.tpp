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

		if (_c.size())
			_c.clear();
		_c = obj._c;
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
		else if (find(_c.begin(), _c.end(), nb) == _c.end())
			_c.push_back(nb);
		else
			throw std::runtime_error(ERR_DUP_VALUES);

		if (_c.size() == MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}
}

template <typename T>
void	PmergeMe<T>::mergeInsert()
{
	bool isOdd = false;
	size_t odd, last = _c.size() - 2;
	if (_c.size() % 2 != 0)
		{ odd = _c.back(); last -= 1; isOdd = true; }

	for (size_t i = 0; i < last; i++)
	{
		if (_c[i] < _c[i + 1])
		{
			_small.push_back(_c[i]);
			_c.erase(_c.begin() + i);
		}
	}

	if (isOdd)
		_c.push_back(odd);
}

template <typename T>
void	PmergeMe<T>::process()
{
	printBefore();

	if (_c.size() > 1)
		mergeInsert();
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << "Before:\t";
	for (size_t i = 0; i < _c.size(); i++)
		std::cout << _c[i] << " ";
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
	return this->_c;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerName() const
{
	return this->_type == VECTOR_TYPE ? "std::vector : " : "std::deque : ";
}
