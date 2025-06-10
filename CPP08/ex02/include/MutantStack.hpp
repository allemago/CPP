#pragma once

# include <stack>
# include <deque>
# include <vector>
# include <iterator>
# include <iostream>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	MutantStack();
	MutantStack(const MutantStack<T, C>&);
	virtual ~MutantStack();
	MutantStack<T, C>&	operator=(const MutantStack<T, C>&);

//	======================= Typedefs ============================

	typedef typename C::iterator                iterator;
	typedef typename C::reverse_iterator        reverse_iterator;
	typedef typename C::const_iterator          const_iterator;
	typedef typename C::const_reverse_iterator  const_reverse_iterator;

//	==================== Public Methods =========================

	iterator                begin();
	iterator                end();

	const_iterator          cbegin() const;
	const_iterator          cend() const;

	reverse_iterator        rbegin();
	reverse_iterator        rend();
	
	const_reverse_iterator  crbegin() const;
	const_reverse_iterator  crend() const;
};

#include "MutantStack.tpp"
