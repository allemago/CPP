#include "../include/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : _rawSequence("")
{ parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const std::string& raw) : _rawSequence(raw)
{ _hasOdd.flag = false; parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& obj) { *this = obj; }

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>&	PmergeMe<T>::operator=(const PmergeMe<T>& obj)
{
	if (this != &obj)
	{
		this->_rawSequence = obj._rawSequence;
		this->_mainChain = obj._mainChain;
		this->_pending = obj._pending;
		this->_hasOdd.flag = obj._hasOdd.flag;
		this->_hasOdd.unpaired = obj._hasOdd.unpaired;
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
	if (isSequenceEmpty() || !_type)
		throw std::runtime_error(!_type ? ERR_TYPE : std::string(EMPTY) + USAGE);

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

		std::pair<size_t, int> newPair(0, nb);

		if (find(_mainChain.begin(), _mainChain.end(), newPair) == _mainChain.end())
			_mainChain.push_back(newPair);
		else
			throw std::runtime_error(ERR_DUP_VALUES);

		if (_mainChain.size() == MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}
	setInsertionIndexes(_mainChain);
}

/*

                                       unpaired
raw = (12, 1) (15, 2) (558, 6) (85, 9) (984551) size = 9

flag = true, unpaired[0] = 984551;

mainChain avant trie des paires
(12, 1) (15, 2) (558, 6) (85, 9) size  = 8
 0   1   2   3   4    5   6   7 

mainChain apres trie des paires: petit a gauche, grand a droite
(1, 12) (2, 15) (6, 558) (9, 85)
 0  0    1  1    2  2     3  3

mainChain apres extraction des min (_pending), reste les grands + ajout du petit
(12) (15) (558) (85)
 0    1    2     3

_pending apres HANDLE_MIN
(1) (2) (6) (9)
 0   1   2   3

*suite de Jacobsthal = ...1, 3, 5, 11, 21, 43, 85, 171...

*/

template <typename T>
typename PmergeMe<T>::iterator	PmergeMe<T>::findByKey(T& c, size_t key)
{
	for (iterator target = c.begin(); target != c.end(); ++target)
	{
		if (target->first == key)
			return target;
	}

	return c.end();
}
template <typename T>
typename PmergeMe<T>::iterator	PmergeMe<T>::binarySearch(typename PmergeMe<T>::iterator it)
{
 	iterator low = _mainChain.begin();
	iterator high = findByKey(_mainChain, it->first);

	while (low < high)
	{
		iterator mid = low + (high - low) / 2;

		if (mid->second < it->second)
			low = mid + 1;
		else
			high = mid;
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

template <typename T>
void	PmergeMe<T>::getOrder(std::vector<size_t>& order, size_t size)
{
	if (order.size())
		order.clear();

	size_t index = 0;
	if (size < 2)
		order.insert(order.begin(), 1);
	else
	{
		index = jacobsthal(2);
		for (size_t i = 3; index < size; i++)
		{
			order.insert(order.end(), index);
			index = jacobsthal(i);
		}
		if (order.back() != size)
			order.insert(order.end(), size);
	}

}

template <typename T>
void	PmergeMe<T>::insertValue(typename PmergeMe<T>::iterator it, size_t max)
{
	size_t inserted = 0;

	while (inserted < max && it >= _pending.begin())
	{
		_mainChain.insert(binarySearch(it), *it);
		++inserted;
		--it;
	}

	it = _pending.begin();
	std::advance(it, max);
	_pending.erase(_pending.begin(), it);
}

template <typename T>
void	PmergeMe<T>::insertPending()
{
	std::vector<size_t> order;
	getOrder(order, _pending.size());

	while (_pending.size())
	{
		size_t orderSize = order.size();

		for (size_t index = 0; index < orderSize; index++)
		{
			size_t max = (order[index] > 1 ? order[index] - order[index - 1] : 1);
			size_t start = max - 1;

			insertValue(_pending.begin() + start, max);
		}

		if (_hasOdd.flag)
		{
			_pending = _hasOdd.unpaired;
			getOrder(order, _pending.size());
			_hasOdd.flag = false;
		}
	}
}

template <typename T>
void	PmergeMe<T>::setInsertionIndexes(T& c)
{
	size_t end = c.size();
	for (size_t i = 0; i < end; i++)
	{
		if (i % 2 == 0)
			c[i].first = (i ? c[i - 1].first + 1 : 1);
		else
			c[i].first = c[i - 1].first;
	}

	if (_hasOdd.flag)
		_hasOdd.unpaired[0].first = c.back().first + 2;
}

template <typename T>
void	PmergeMe<T>::handleUnpaired(size_t start, size_t end)
{
	_hasOdd.unpaired.insert(_hasOdd.unpaired.begin(),
							_mainChain.begin() + start,
							_mainChain.begin() + end);

	_mainChain.erase(_mainChain.begin() + start, _mainChain.begin() + end);
}

template <typename T>
void	PmergeMe<T>::mergeInsertSort(e_Mode mode, size_t size, size_t start, size_t pairs)
{
	if (size <= 1 || pairs > size / 2) // avant -> >=
		return ;

	size_t end = ((size / pairs) * pairs);
	if (mode == HANDLE_MAX && !_hasOdd.flag)
	{	
		_hasOdd.flag = (end != size);
		if (_hasOdd.flag)
			handleUnpaired(end, size);
	}

	size_t max = (mode != HANDLE_MIN ? end : size / 2);
	size_t incr = (mode != HANDLE_MIN ? pairs * 2 : 1);

	for (size_t i = start; i < max; i+=incr)
	{
		switch (mode)
		{
			case HANDLE_MAX:
				if (_mainChain[i].second < _mainChain[i - pairs].second)
					std::swap_ranges(_mainChain.begin() + (i - pairs) + 1,
									_mainChain.begin() + i + 1,
									_mainChain.begin() + (i - (pairs * 2)) + 1);
				break ;

			case HANDLE_MIN:
				_pending.push_back(_mainChain[i]);
				_mainChain.erase(_mainChain.begin() + i);
		}
	}

	if (mode == HANDLE_MAX)
	{
		if (pairs == 2 && _pending.empty())
			setInsertionIndexes(_mainChain);
		
		mergeInsertSort(HANDLE_MAX, size, start + pairs * 2, pairs * 2);
	}
	else if (mode == HANDLE_MIN)
		insertPending();
}

template <typename T>
void	PmergeMe<T>::process()
{
	mergeInsertSort(HANDLE_MAX, _mainChain.size(), 1, 1);
	mergeInsertSort(HANDLE_MIN, _mainChain.size(), 0, 1);
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << YELLOW "Before:\t" RESET;
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << _mainChain[i].second << " ";
	std::cout << "\n";
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	double duration = obj.getDuration();

	const T& c = obj.getContainer();
	
	os << YELLOW "\nAfter:\t" RESET;
	size_t size = c.size();
	for (size_t i = 0; i < size; i++)
		os << c[i].second << (i + 1 != size ? " " : "\n");
	os << "\nTime to process a range of\t" << size;
	os << " elements with " << obj.getContainerType() << " : ";
	os << std::fixed << std::setprecision(5) << duration << " us";

	os << obj.isSorted();

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

// DEBUG FUNCTIONS

template <typename T>
void	PmergeMe<T>::printMainChain() const
{
	std::cout << PURPLE "\nmainChain:\n" RESET;
	for (size_t i = 0; i < _mainChain.size(); i++)
		std::cout << "index = " << _mainChain[i].first << BOLD ", value = " << _mainChain[i].second << "\n" RESET;
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printPending() const
{
	std::cout << GREEN "\npending:\n" RESET;
	for (size_t i = 0; i < _pending.size(); i++)
		std::cout << "index = " << _pending[i].first << BOLD ", value = " << _pending[i].second << "\n" RESET;
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printOdd() const
{
	std::cout << BLUE "\nunpaired:\n" RESET;
	for (size_t i = 0; i < _hasOdd.unpaired.size(); i++)
		std::cout << "index = " << _hasOdd.unpaired[i].first << BOLD ", value = " << _hasOdd.unpaired[i].second << "\n" RESET;
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printOrder(const std::vector<size_t>& c) const
{
	std::cout << CYAN "\nJacobsthal order: " RESET;
	for (size_t i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << "\n";
}

template <typename T>
const std::string	PmergeMe<T>::isSorted() const
{
	bool sorted = true;
	for (size_t i = 0; i < _mainChain.size() - 1; i++)
	{
		if (_mainChain[i].second > _mainChain[i + 1].second)
		{
			sorted = false;
			break ;
		}
	}
	return sorted ? "\n\nSequence is sorted ✅" : "\n\nSequence is not sorted ❌";
}

// DEBUG FUNCTIONS
