template <typename T, typename C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>() {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C>& copy) : std::stack<T, C>()
{
	*this = copy;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

template <typename T, typename C>
MutantStack<T, C>&	MutantStack<T, C>::operator=(const MutantStack<T, C>& copy)
{
	if (this != &copy)
		std::stack<T, C>::operator=(copy);
	return (*this);
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin()
{
	return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end()
{
	return (this->c.end());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator	MutantStack<T, C>::cbegin() const
{
	return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator	MutantStack<T, C>::cend() const
{
	return (this->c.end());
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator	MutantStack<T, C>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator	MutantStack<T, C>::rend()
{
	return (this->c.rend());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator	MutantStack<T, C>::crbegin() const
{
	return (this->c.rbegin());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator	MutantStack<T, C>::crend() const
{
	return (this->c.rend());
}
