#include "../include/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : _rawSequence("") { parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const std::string& raw) : _rawSequence(raw) { parseSequence(); }

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
		this->_size = obj._size;
		this->_sequence = obj._sequence;
		this->_mainChain = obj._mainChain;
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

		std::pair<int, int> newPair(0, nb);

		if (find(_sequence.begin(), _sequence.end(), newPair) == _sequence.end())
			_sequence.push_back(newPair);
		else
			throw std::runtime_error(ERR_DUP_VALUES);

		if (_sequence.size() > MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}

	_size = _sequence.size();
	if (_size < 2)
		_mainChain = _sequence;
}

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
typename PmergeMe<T>::iterator	PmergeMe<T>::binarySearch(typename PmergeMe<T>::iterator toInsert,
														typename PmergeMe<T>::iterator high)
{
 	iterator low = _mainChain.begin();

	while (low < high)
	{
		iterator mid = low + (high - low) / 2;

		if (mid->second < toInsert->second)
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
	size_t index = 0;

	if (size == 1)
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
void	PmergeMe<T>::insertValue(T& pending, typename PmergeMe<T>::iterator toInsert, size_t max)
{
	while (toInsert >= pending.begin())
	{	
		iterator pos = binarySearch(toInsert, findByKey(_mainChain, toInsert->first));
		_mainChain.insert(pos, *toInsert);

		--toInsert;
	}

	toInsert = pending.begin();
	std::advance(toInsert, max);
	pending.erase(pending.begin(), toInsert);
}

template <typename T>
void	PmergeMe<T>::insertPending(T& pending, T& leftover)
{
	std::vector<size_t> order;
	getOrder(order, pending.size());
	size_t orderSize = order.size();

	for (size_t i = 0; i < orderSize; i++)
	{
		size_t max = (order[i] > 1 ? order[i] - order[i - 1] : 1);
		size_t start = max - 1;

		insertValue(pending, pending.begin() + start, max);
	}

	if (!leftover.empty())
	{
		iterator pos = binarySearch(leftover.begin(), _mainChain.end());
		_mainChain.insert(pos, leftover[0]);
		leftover.clear();
	}
}

template <typename T>
void	PmergeMe<T>::setKeys(T& pending)
{
	size_t start = (pending.size() - _mainChain.size());
	size_t size = _mainChain.size();

	for (size_t i = 0; i < size; i++)
	{
		pending[start].first = _mainChain[i].second;
		start++;
	}
}

template <typename T>
void	PmergeMe<T>::insertErase(T& dest, T& src, typename PmergeMe<T>::iterator it)
{
	dest.push_back(*it);
	src.erase(it);
}

template <typename T>
bool	PmergeMe<T>::isOdd(T& leftover, T& src, size_t size)
{
	if (size % 2 != 0)
	{
		insertErase(leftover, src, src.end() - 1);
		return true;
	}

	return false;
}

// Exemple:

// Sequence brut avant premier sort:
// _sequence = [12 4 7 1 9 3 15 6 11 2]

// Apres premier sort (Level 0)
// _mainChain = [12, 7, 9, 15, 11]
// pending = [4, 1, 3, 6, 2]

// Apres deuxieme sort (recursion Level 1)
// _mainChain = [12, 15] 
// pending = [7, 9]
// leftover = [11]

// Apres troisieme sort (recursion Level 2)
// _mainChain = [15] 
// pending = [12]

// Recursion Level 3 -> Return car _mainChain size <= 1;
// Retour recursion

// Retour a la suite du code du Level 2 -> insertPending
// _mainChain = [15]
// pending = [12]
// order (Jacobsthal) = [1]
// Apres insertPending():
// _mainChain (apres) = [12, 15]

// Retour a la suite du code du Level 1 -> insertPending
// _mainChain = [12, 15]
// pending = [7, 9]
// leftover = [11]
// order (Jacobsthal) = [1, 2]
// Apres insertPending():
// _mainChain (apres) = [7, 9, 11, 12, 15]

// Retour a la suite du code du Level 0 -> insertPending
// _mainChain = [7, 9, 11, 12, 15]
// pending = [4, 1, 3, 6, 2]
// order (Jacobsthal) = [1, 3, 5]
// Apres insertPending():
// _mainChain (apres) = [1, 2, 3, 4, 6, 7, 9, 11, 12, 15]

template <typename T>
void	PmergeMe<T>::mergeInsertSort(e_Mode mode)
{
	T& c = (mode == HANDLE_SEQUENCE ? _sequence : _mainChain);
	T pending;
	T leftover;

	size_t size = c.size();

	if (size <= 1)
		return ;

	if (isOdd(leftover, c, size))
		size = c.size();

	for (size_t i = 0; i < size / 2; i++)
	{
		size_t left = i;
		size_t right = i + 1;

		switch (mode)
		{
			case HANDLE_SEQUENCE:
				if (c[0].second < c[1].second)
				{
					insertErase(pending, c, c.begin());
					insertErase(_mainChain, c, c.begin());
				}
				else
				{
					insertErase(_mainChain, c, c.begin());
					insertErase(pending, c, c.begin());
				}
				break ;
			
			case HANDLE_MAINCHAIN:
				if (c[left].second < c[right].second)
					insertErase(pending, c, c.begin() + left);
				else
					insertErase(pending, c, c.begin() + right);
		}
	}

	setKeys(pending);

	mergeInsertSort(HANDLE_MAINCHAIN);

	insertPending(pending, leftover);
}

template <typename T>
void	PmergeMe<T>::printBefore() const
{
	std::cout << YELLOW "Before:\t" RESET;
	size_t size = _sequence.size();
	for (size_t i = 0; i < size; i++)
		std::cout << _sequence[i].second << (i + 1 != size ? " " : "\n");
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
	std::cout << std::fixed << std::setprecision(1) << duration << " us\n";

	std::cout << BOLD << isSorted() << RESET;
}

template <typename T>
double	PmergeMe<T>::getDuration() const
{
	return (static_cast<double>(clock() - g_startTime) / CLOCKS_PER_SEC) * 1000000.0;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerType() const
{
	return this->_type == VECTOR_TYPE ? "std::vector" : "std::deque";
}

// DEBUG FUNCTIONS

template <typename T>
void	PmergeMe<T>::printSequence() const
{
	std::cout << PURPLE "\n_sequence:\n" RESET;
	size_t size = _sequence.size();
	for (size_t i = 0; i < size; i++)
		std::cout << "index = " << _sequence[i].first << BOLD ", value = " << _sequence[i].second << "\n" RESET;
	std::cout << "\n";
}

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
void	PmergeMe<T>::printPending(T& pending) const
{
	std::cout << GREEN "\npending:\n" RESET;
	size_t size = pending.size();
	for (size_t i = 0; i < size; i++)
		std::cout << "index = " << pending[i].first << BOLD ", value = " << pending[i].second << "\n" RESET;
	std::cout << "\n";
}

template <typename T>
void	PmergeMe<T>::printLeftover(T& leftover) const
{
	std::cout << BLUE "\nleftover:\n" RESET;
	if (!leftover.empty())
		std::cout << "index = " << leftover[0].first << BOLD ", value = " << leftover[0].second << "\n\n" RESET;
}

template <typename T>
void	PmergeMe<T>::printOrder(std::vector<size_t>& order) const
{
	std::cout << CYAN "\nJacobsthal order: " RESET;
	size_t size = order.size();
	for (size_t i = 0; i < size; i++)
		std::cout << order[i] << " ";
	std::cout << "\n";
}

template <typename T>
const std::string	PmergeMe<T>::isSorted() const
{
	bool sorted = true;
	
	size_t size = _mainChain.size();
	if (size > 1)
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			if (_mainChain[i].second > _mainChain[i + 1].second)
			{
				sorted = false;
				break ;
			}
		}
	}

	if (size != this->_size)
	{
		std::cout << "\n" BOLD << this->_size - _mainChain.size() << " elements are missing ❌" RESET << std::endl;
		std::cout << BOLD << "Before = " GREEN << this->_size << " elements\n" RESET;
		std::cout << BOLD "After = " RED << _mainChain.size() << " elements" << RESET;
	}

	return sorted ? "\nSequence is sorted ✅\n" : "\nSequence is not sorted ❌\n";
}

// DEBUG FUNCTIONS
