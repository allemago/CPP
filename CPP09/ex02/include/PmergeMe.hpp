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
	MAX_SEARCH = 1,
	MIN_SEARCH = 2
};

enum	e_Name
{
	MAINCHAIN = 1,
	RAW = 2
};

// TYPE TRAITS
template <typename T>
struct ContainerTypeTraits;

template <>
struct ContainerTypeTraits< std::deque<int> >
{
	static const e_Type value = DEQUE_TYPE;
};

template <>
struct ContainerTypeTraits< std::vector<int> >
{
	static const e_Type value = VECTOR_TYPE;
};

// STRUCTURE
struct s_OddFlag
{
	bool  isOdd;
	int   straggler;
};


// TEMPLATE CLASS
template <typename T>
class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string               _sequence;

	static const e_Type       _type = ContainerTypeTraits<T>::value;
	T                         _raw;
	T                         _mainChain;
	s_OddFlag                 _oddFlag;

//	==================== Private Methods ========================

	void    parseSequence();
	bool    isSequenceEmpty() const;
	void    sort(e_Mode, size_t, size_t, size_t);

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
	const T&             getContainer(e_Name) const;
	const std::string    getContainerType() const;

//	==================== Public Methods =========================

	void	process();
};

# include "PmergeMe.tpp"
