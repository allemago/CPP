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

		if (_rawSequence.size())
			_rawSequence.clear();
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
size_t	PmergeMe<T>::binarySearch(size_t target) const
{
	size_t low = 0, mid = 0;
	size_t high = _mainChain.size() - 1;

	while (low <= high)
	{
		mid = low + (high - low) / 2;

		if (mid == target)
			return mid;

		if (mid < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

template <typename T>
size_t	PmergeMe<T>::jacobsthal(size_t n) const
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

/*
                                       straggler
raw = (12, 1) (15, 2) (558, 6) (85, 9) (984551) size = 9

isOdd = true, straggler = 984551;

mainChain avant trie des paires
(12, 1) (15, 2) (558, 6) (85, 9) size  = 8
 0   1   2   3   4    5   6   7 

mainChain apres trie des paires
(1, 12) (2, 15) (6, 558) (9, 85)
 0  1    2  3    4  5     6  7

mainChain apres ajout des grands derriere le min
(1) (12) (15) (558) (85)
 0   1    2    3     4

_pending apres HANDLE_MIN
(2) (6) (9)
 0   1   2 

*/

template <typename T>
void	PmergeMe<T>::insertPending()
{
	;
}

template <typename T>
void	PmergeMe<T>::mergeInsertSort(e_Mode mode, size_t size, size_t start, size_t pairs)
{
	if (size <= 1 || pairs >= size / 2)
		return ;

	size_t end = ((size / pairs) * pairs);
	_oddFlag.isOdd = (end != size);
	if (_oddFlag.isOdd)
		extractStraggler(size, end);

	T& c = (mode != HANDLE_ODD ? _mainChain : _oddFlag.straggler);
	size_t max = (mode != HANDLE_MIN ? end : size / 2);
	size_t incr = (mode != HANDLE_MIN ? pairs * 2 : 1);

	for (size_t i = start; i < max; i+=incr)
	{
		switch (mode)
		{
			case HANDLE_MAX:
			case HANDLE_ODD:
				if (c[i] < c[i - pairs])
					std::swap_ranges(c.begin() + (i - pairs) + 1,
									c.begin() + i + 1,
									c.begin() + (i - (pairs * 2)) + 1);
				break ;

			case HANDLE_MIN:
				_pending.push_back(c[i]);
				_mainChain.erase(_mainChain.begin() + i);
				break ;
		}
	}

	if (mode == HANDLE_MAX || mode == HANDLE_ODD) // DEBUG
		std::cout << "pairs = " << pairs << "\n";
	else
		std::cout << "\n";
	printBefore();
	std::cout << "\n"; // DEBUG

	if (mode == HANDLE_MAX)
		mergeInsertSort(HANDLE_MAX, size, start + pairs * 2, pairs * 2);

	else if (mode == HANDLE_MIN)
		insertPending();
}

template <typename T>
void	PmergeMe<T>::process()
{
	std::cout << "\n"; // DEBUG
	
	mergeInsertSort(HANDLE_MAX, _mainChain.size(), 1, 1);

	if (_oddFlag.isOdd)
		mergeInsertSort(HANDLE_ODD, _oddFlag.straggler.size(), 1, 1);
	
	mergeInsertSort(HANDLE_MIN, _mainChain.size(), 0, 1);
}

template <typename T>
void	PmergeMe<T>::extractStraggler(size_t size, size_t end)
{
	_oddFlag.straggler.insert(_oddFlag.straggler.begin(),
							_mainChain.begin() + end,
							_mainChain.begin() + size);

	_mainChain.erase(_mainChain.begin() + end, _mainChain.begin() + size);
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << YELLOW "Before:\t" RESET;
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain[i] << " ";
	std::cout << "\n";
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	double duration = obj.getDuration();

	T c = obj.getContainer();
	
	os << YELLOW "\nAfter:\t" RESET;
	size_t size = c.size();
	for (size_t i = 0; i < size; i++)
		os << c[i] << (i + 1 != size ? " " : "\n");
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
const T&	PmergeMe<T>::getContainer() const
{
	return this->_mainChain;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerType() const
{
	return this->_type == VECTOR_TYPE ? "std::vector" : "std::deque";
}
