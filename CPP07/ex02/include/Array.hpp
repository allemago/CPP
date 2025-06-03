/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:21:42 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/03 17:49:31 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
class Array
{
/*****************
*    PRIVATE     *
*****************/
private:

	T*		_array;
	size_t	_n;

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	Array() : _n(0), _array(NULL) {}
	
	Array(size_t n) : _n(n), _array(NULL)
	{
		this->_array = new T[this->_n];
	}

	Array(const Array& object) : _n(object._n), _array(NULL)
	{
		*this = object;
	}

	Array& operator=(const Array& object)
	{
		if (this != &object)
		{
			if (this->_array)
			{
				for (int i = 0; i < _n; i++)
					delete this->_array[i];
				delete[] this->_array;
				this->_array = NULL;
			}
			this->_array = new T[object._n];
		}
		return (*this);
	}
	
	~Array()
	{
		for (size_t i = 0; i < this->_n; i++)
			delete[] _array[i];
		delete[] _array;
	}
	
	Array&	operator=(const Array&);

//	==================== Custom Constructors ====================
//	==================== Getters / Setters ======================
//	==================== Public Methods =========================
//	==================== Exceptions =============================
};
