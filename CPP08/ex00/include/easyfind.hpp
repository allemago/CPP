#pragma once

# include <iostream>
# include <algorithm>
# include <vector>

class NoOccurrenceFound : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("No occurrence found");
		}
};

template <typename T>
typename T::iterator	easyfind(T& t, int x)
{
	typename T::iterator it = std::find(t.begin(), t.end(), x);

	if (it == t.end())
		throw NoOccurrenceFound();
	
	std::cout << "An occurrence was found: ";

	return (it);
}
