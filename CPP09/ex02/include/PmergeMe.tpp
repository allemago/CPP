#include "../include/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() : _sequence("") { parseSequence(); }

template <typename T>
PmergeMe<T>::PmergeMe(const std::string& raw) : _sequence(raw) { parseSequence(); }

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
		_sequence = obj._sequence;

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
	return _sequence.find_first_not_of(WHITESPACE) == std::string::npos;
}

template <typename T>
void	PmergeMe<T>::parseSequence()
{
	if (isSequenceEmpty())
		throw std::runtime_error(USAGE);

	std::istringstream issSeq(_sequence);
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
		else if (find(_raw.begin(), _raw.end(), nb) == _raw.end())
			_raw.push_back(nb);
		else
			throw std::runtime_error(ERR_DUP_VALUES);

		if (_raw.size() == MAX_SIZE)
			throw std::runtime_error(MAX_SIZE_REACHED);
	}

	_mainChain = _raw;
}

template <typename T>
void	PmergeMe<T>::sort(e_Mode mode, size_t size, size_t start, size_t pairs)
{
	if (pairs == size / 2)
		return ;

	T pending;
	size_t end = size - start - pairs;
	for (size_t i = start; i < end; i+=(pairs * 2))
	{
		switch (mode)
		{
			case MAX_SEARCH:
				if (_mainChain[i] > _mainChain[i + pairs])
					std::swap_ranges(_mainChain.begin() + i,
									_mainChain.begin() + (i + pairs),
									_mainChain.begin() + (i + pairs));
				break ;

			case MIN_SEARCH:
				if (i > 1)
				{

					std::swap_ranges(_mainChain.begin() + (i + 1),
									_mainChain.begin() + (i + 2),
									_mainChain.begin() + ((i + 1) / 2) + 1);
				}
				break ;
		}
	}

	if (mode == MAX_SEARCH)
		sort(MAX_SEARCH, size, start + pairs, pairs * 2);
}

/*
                                       straggler
raw = (12, 1) (15, 2) (558, 6) (85, 9) (984551) size = 9

isOdd = true, straggler = 984551;

mainChain avant
(12, 1) (15, 2) (558, 6) (85, 9) size  = 8
 0   1   2   3   4    5   6   7 

mainChain apres
(1, 12) (2, 15) (6, 558) (9, 85)
 0  1    2  3    4  5     6  7 

*/

template <typename T>
void	PmergeMe<T>::process()
{
	 _oddFlag.isOdd = (_mainChain.size() % 2 != 0);
	if (_oddFlag.isOdd)
	{
		_oddFlag.straggler = _mainChain.back();
		_mainChain.pop_back();
	}

	size_t size = _mainChain.size();

	if (size > 1)
	{
		sort(MAX_SEARCH, size, 0, 1);

		sort(MIN_SEARCH, size, 2, 1);
	}
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	double duration = obj.getDuration();

	T c1 = obj.getContainer(RAW);

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
	return name == RAW ? this->_raw : this->_mainChain;
}

template <typename T>
const std::string	PmergeMe<T>::getContainerType() const
{
	return this->_type == VECTOR_TYPE ? "std::vector" : "std::deque";
}

