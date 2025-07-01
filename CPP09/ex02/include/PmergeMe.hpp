#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <set>
# include <utility>
# include <algorithm>
# include <iterator>
# include <exception>
# include <sstream>
# include <limits>
# include <sys/time.h>
# include <cmath>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

# define USAGE "Usage: ./PmergeMe [positive integer sequence]"
# define ERR_TYPE "Unsupported container type. Please use vector or deque"
# define MAX_SIZE_REACHED "Maximum of 5000 integers has been reached"
# define ERR_DUP_VALUES "Error: duplicate values are not allowed"

# define MAX_SIZE 5000
# define MICRO_SEC 1000000.0
# define WHITESPACE "\t\n\v\f\r "

template <typename T>
class PmergeMe;

// GLOBAL VARIABLE
extern clock_t g_startTime;

// ENUM
enum	e_Type
{
	INVALID_TYPE = 0,
	DEQUE_TYPE = 1,
	VECTOR_TYPE = 2
};

enum	e_Mode
{
	HANDLE_MAX = 1,
	HANDLE_ODD = 2,
	HANDLE_MIN = 3,
	HANDLE_ODD_INSERT = 4
};

// TYPE TRAITS
template <typename T>
struct	ContainerTypeTraits
{
	static const e_Type value = INVALID_TYPE;
};

template <>
struct	ContainerTypeTraits< std::deque< std::pair<size_t, int> > >
{
	static const e_Type value = DEQUE_TYPE;
};

template <>
struct	ContainerTypeTraits< std::vector< std::pair<size_t, int> > >
{
	static const e_Type value = VECTOR_TYPE;
};

// STRUCTURES
template <typename T>
struct	HasOdd
{
	bool    flag;
	T       unpaired;
};

// TEMPLATE CLASS
template <typename T>
class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string                              _rawSequence;

	static const e_Type                      _type = ContainerTypeTraits<T>::value;
	T                                        _mainChain;
	T                                        _pending;

	HasOdd<T>                                _hasOdd;

//	====================== Typedefs =============================

	typedef typename T::iterator                  iterator;
	typedef typename std::pair<size_t, int>       Pair;
	typedef typename std::vector<Pair>            PairList;
	typedef typename PairList::iterator           pair_iterator;

//	==================== Private Methods ========================

	void             parseSequence();
	bool             isSequenceEmpty() const;
	void             mergeInsertSort(e_Mode, size_t, size_t, size_t);
	void             handleUnpaired(size_t, size_t);
	void             setIndexes();
	void             insertPending();
	void             insertValue(iterator, pair_iterator);
	void             getJacobsthalOrder(std::vector<size_t>&, size_t);
	size_t           jacobsthal(size_t) const;
	iterator         binarySearch(pair_iterator);

	// DEBUG FUNCTIONS
	void             printPending() const;
	void             printMainChain() const;
	void             printOrder(const std::vector<size_t>&) const;

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	PmergeMe();
	PmergeMe(const PmergeMe<T>&);
	~PmergeMe();
	PmergeMe<T>&	operator=(const PmergeMe<T>&);
	
//	==================== Custom Constructors ====================

	PmergeMe(const std::string&);

//	======================== Getters ============================

	double               getDuration() const;
	const T&             getContainer() const;
	const std::string    getContainerType() const;

//	==================== Public Methods =========================

	void                 printBefore() const;
	void                 process();
};

# include "PmergeMe.tpp"
