/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:51:54 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/04 14:59:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _n(0), _array(NULL) {}

template <typename T>
Array<T>::Array(size_t n) : _n(n), _array(NULL)
{
	if (size() > 0)
		this->_array = new T[size()]();
}

template <typename T>
Array<T>::Array(const Array<T>& object) : _n(object.size()), _array(NULL)
{
	*this = object;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& object)
{
	if (this != &object)
	{
		if (this->_array)
		{
			delete[] this->_array;
			this->_array = NULL;
		}
		this->_n = object.size();
		this->_array = new T[object.size()]();
		for (size_t i = 0; i < size(); i++)
			this->_array[i] = object._array[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](size_t index) const
{
	if (index >= size())
		throw indexOutOfBounds();
	
	return (this->_array[index]);
}

template <typename T>
size_t	Array<T>::size() const
{
	return (this->_n);
}

template <typename T>
const char*	Array<T>::indexOutOfBounds::what() const throw()
{
	return (OUT_OF_BOUNDS);
}
