#include "../include/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : _rawSequence("")
{ parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const std::string& raw) : _rawSequence(raw)
{ parseSequence(); }

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
		this->_order = obj._order;
		this->_leftover = obj._leftover;
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
	_size = _mainChain.size();
}

/*
                                       leftover
raw = (12, 1) (15, 2) (558, 6) (85, 9) (984551) size = 9

flag = true, leftover[0] = 984551;

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
typename PmergeMe<T>::iterator	PmergeMe<T>::findByKey(T& c, int key)
{
	for (iterator target = c.begin(); target != c.end(); ++target)
	{
		if (target->second == key)
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
void	PmergeMe<T>::getOrder()
{
	if (_order.size())
		_order.clear();

	size_t size = _pending.size();
	size_t index = 0;
	if (size == 1)
		_order.insert(_order.begin(), 1);
	else
	{
		index = jacobsthal(2);
		for (size_t i = 3; index < size; i++)
		{
			_order.insert(_order.end(), index);
			index = jacobsthal(i);
		}
		if (_order.back() != size)
			_order.insert(_order.end(), size);
	}

}

template <typename T>
void	PmergeMe<T>::insertValue(typename PmergeMe<T>::iterator it, size_t max)
{
	while (it >= _pending.begin())
	{	
		_mainChain.insert(binarySearch(it), *it);
		--it;
	}

	it = _pending.begin();
	std::advance(it, max);
	_pending.erase(_pending.begin(), it);

	if (!_leftover.empty())
	{
		_mainChain.insert(binarySearch(_leftover.begin()), _leftover[0]);
		_leftover.clear();
	}
}

template <typename T>
void	PmergeMe<T>::insertPending()
{
	getOrder();

	size_t orderSize = _order.size();

	for (size_t index = 0; index < orderSize; index++)
	{
		size_t max = (_order[index] > 1 ? _order[index] - _order[index - 1] : 1);
		size_t start = max - 1;

		insertValue(_pending.begin() + start, max);
	}
}

template <typename T>
void	PmergeMe<T>::setInsertionIndexes()
{
	size_t start = (_pending.size() -  _mainChain.size());
	size_t end = _mainChain.size();
	size_t i = 0;

	while (start < end)
	{
		_pending[start].first = _mainChain[i++].second;
		start++;
	}

	if (!_leftover.empty())
		_leftover.back().first = _pending.back().first + 1;
}

template <typename T>
void	PmergeMe<T>::insertErase(T& c, typename PmergeMe<T>::iterator it)
{
	c.push_back(*it);
	_mainChain.erase(it);
}

template <typename T>
bool	PmergeMe<T>::isOdd(size_t size)
{
	if (size % 2 != 0)
	{
		/* if (!_leftover.empty())
			_leftover.clear(); */

		return insertErase(_leftover, _mainChain.end() - 1), true;
	}

	return false;
}

template <typename T>
void	PmergeMe<T>::mergeInsertSort(size_t size)
{
	if (size <= 1)
		return ;

	if (isOdd(size))
		size = _mainChain.size();

	for (size_t i = 0; i < size / 2; i++)
	{
		_mainChain[0].second < _mainChain[1].second ?
		insertErase(_pending, _mainChain.begin()) : insertErase(_pending, _mainChain.begin() + 1);
	}
	
	setInsertionIndexes();

	mergeInsertSort(_mainChain.size());

	if (!_pending.empty())
		insertPending();
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << YELLOW "Before:\t" RESET;
	size_t size = _mainChain.size();
	for (size_t i = 0; i < size; i++)
		std::cout << _mainChain[i].second << (i + 1 != size ? " " : "\n");
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printAfter() const
{
	double duration = getDuration();

	std::cout << YELLOW "After:\t" RESET;
	size_t size = _mainChain.size();
	for (size_t i = 0; i < size; i++)
		std::cout << _mainChain[i].second << (i + 1 != size ? " " : "\n");
	
	std::cout << "\nTime to process a range of\t" << size;
	std::cout << " elements with " << getContainerType() << " : ";
	std::cout << std::fixed << std::setprecision(5) << duration << " us\n";

	printPending(); // DEBUG
	printOdd(); // DEBUG

	std::cout << isSorted();
}

template <typename T>
double	PmergeMe<T>::getDuration() const
{
	return (static_cast<double>(clock() - g_startTime) / CLOCKS_PER_SEC) * MICRO_SEC;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerType() const
{
	return this->_type == VECTOR_TYPE ? "std::vector" : "std::deque";
}

template <typename T>
size_t	PmergeMe<T>::getSize() const
{
	return _mainChain.size();
}

// DEBUG FUNCTIONS

template <typename T>
void	PmergeMe<T>::printMainChain() const
{
	std::cout << PURPLE "\nmainChain:\n" RESET;
	size_t size = _mainChain.size();
	for (size_t i = 0; i < size; i++)
		std::cout << "index = " << _mainChain[i].first << BOLD ", value = " << _mainChain[i].second << "\n" RESET;
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printPending() const
{
	std::cout << GREEN "\npending:\n" RESET;
	size_t size = _pending.size();
	for (size_t i = 0; i < size; i++)
		std::cout << "index = " << _pending[i].first << BOLD ", value = " << _pending[i].second << "\n" RESET;
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printOdd() const
{
	std::cout << BLUE "\nleftover:\n" RESET;
	if (!_leftover.empty())
		std::cout << "index = " << _leftover[0].first << BOLD ", value = " << _leftover[0].second << "\n\n" RESET;
}

template <typename T>
void	PmergeMe<T>::printOrder() const
{
	std::cout << CYAN "\nJacobsthal order: " RESET;
	size_t size = _order.size();
	for (size_t i = 0; i < size; i++)
		std::cout << _order[i] << " ";
	std::cout << "\n";
}

template <typename T>
const std::string	PmergeMe<T>::isSorted() const
{
	bool sorted = true;
	if (_mainChain.size() != _size)
		std::cout << CYAN << "\nsize before = " << _size << ", size after = " << _mainChain.size() << RESET, sorted = false;
	else
	{
		for (size_t i = 0; i < _mainChain.size() - 1; i++)
		{
			if (_mainChain[i].second > _mainChain[i + 1].second)
			{
				sorted = false;
				break ;
			}
		}
	}
	return sorted ? "\nSequence is sorted ✅\n" : "\nSequence is not sorted ❌\n";
}

// DEBUG FUNCTIONS
