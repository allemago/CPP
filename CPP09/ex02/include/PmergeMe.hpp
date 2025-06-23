#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <utility>
# include <algorithm>
# include <iterator>
# include <exception>
# include <sstream>
# include <limits>
# include <sys/time.h>
# include <cmath>

# define BOLD "\033[1m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"

# define USAGE "Usage: ./PmergeMe [positive integer sequence]"
# define MAX_SIZE_REACHED "Maximum of 5000 integers has been reached"
# define ERR_DUP_VALUES "Error: duplicate values are not allowed"

# define MAX_SIZE 5000
# define MICRO_SEC 1000000.0
# define WHITESPACE "\t\n\v\f\r "

// GLOBAL VARIABLE
extern clock_t g_startTime;

// ENUM
enum	e_Type
{
	DEQUE_TYPE = 1,
	VECTOR_TYPE = 2
};

enum	e_Mode
{
	HANDLE_MAX = 1,
	HANDLE_ODD = 2,
	HANDLE_MIN = 3
};

// TYPE TRAITS
template <typename T>
struct	ContainerTypeTraits;

template <>
struct	ContainerTypeTraits< std::deque<int> >
{
	static const e_Type value = DEQUE_TYPE;
};

template <>
struct	ContainerTypeTraits< std::vector<int> >
{
	static const e_Type value = VECTOR_TYPE;
};

// TEMPLATE STRUCTURE
template <typename T>
struct	OddFlag
{
	bool  isOdd;
	T     straggler;
};


// TEMPLATE CLASS
template <typename T>
class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string               _rawSequence;

	static const e_Type       _type = ContainerTypeTraits<T>::value;
	T                         _mainChain;
	T                         _pending;
	OddFlag<T>                _oddFlag;

//	==================== Private Methods ========================

	void    parseSequence();
	bool    isSequenceEmpty() const;
	void    mergeInsertSort(e_Mode, size_t, size_t, size_t);
	void    insertPending();
	void    extractStraggler(size_t, size_t);
	size_t  jacobsthal(size_t) const;
	size_t  binarySearch(size_t) const;

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

	void    printBefore() const;
	void	process();
};

# include "PmergeMe.tpp"
