#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <map>
# include <utility>
# include <algorithm>
# include <iterator>
# include <exception>
# include <sstream>
# include <limits>
# include <sys/time.h>
# include <cmath>
# include <unistd.h>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

# define EMPTY "Error: empty sequence in parameter\n"
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
	HANDLE_MIN = 1,
	HANDLE_MAX = 2
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

template <typename T>
class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	static const e_Type    _type = ContainerTypeTraits<T>::value;

	std::string            _rawSequence;

	T                      _mainChain;
	T                      _pending;
	T                      _leftover;

	std::vector<size_t>    _order;

//	====================== Typedefs =============================

	typedef typename T::iterator             iterator;

//	==================== Private Methods ========================

	void                 parseSequence();
	bool                 isSequenceEmpty() const;

	void                 insertPending();
	void                 insertValue(iterator, size_t);
	void                 insertErase(T&, iterator);
	bool                 isOdd(size_t);
	
	void                 getOrder();
	size_t               jacobsthal(size_t) const;
	iterator             binarySearch(iterator);

	void                 setInsertionIndexes();
	iterator             findByKey(T&, int);
	double               getDuration() const;
	const std::string    getContainerType() const;
	
//	===================== Debug Methods =========================

	void                 printMainChain() const;
	void                 printPending() const;
	void                 printOdd() const;
	void                 printOrder() const;
	const std::string    isSorted() const;

/*****************
*     PUBLIC     *
*****************/
public:

	PmergeMe();
	PmergeMe(const std::string&);
	PmergeMe(const PmergeMe<T>&);
	~PmergeMe();
	PmergeMe<T>&         operator=(const PmergeMe<T>&);

//	==================== Public Methods =========================

	void                 mergeInsertSort(size_t);

	void                 printBefore() const;
	void                 printAfter() const;

	size_t               getSize() const;
};

# include "PmergeMe.tpp"
