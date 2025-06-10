/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:04:09 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/10 16:56:15 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	typedef typename C::iterator			iterator;
	typedef typename C::reverse_iterator	reverse_iterator;

//	==================== Public Methods =========================

	iterator					begin();
	iterator					end();

	reverse_iterator			rbegin();
	reverse_iterator			rend();
};

#include "MutantStack.tpp"
