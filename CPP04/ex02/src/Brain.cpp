/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:43:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 13:11:57 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE "Brain " RESET << "default constructor called" << std::endl;
}

Brain::Brain(const std::string idea, const size_t i)
{
	std::cout << BLUE "Brain " RESET << "constructor with parameter called" << std::endl;
	setIdea(idea, i);
}

Brain::Brain(const Brain& object)
{
	*this = object;
}

Brain::~Brain()
{
	std::cout << BLUE "Brain " RESET << "destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& object)
{
	std::cout << BLUE "Brain " RESET << "copy assignment constructor called" << std::endl;
	if (this != &object)
	{
		for (size_t i = 0; i < 100; i++)
			setIdea(object._ideas[i], i);
	}
	return (*this);
}

void	Brain::setIdea(const std::string& idea, const size_t i)
{
	if (!idea.empty() && i >= 0 && i < 100)
		this->_ideas[i] = idea;
}

const std::string&	Brain::getIdea(int idx) const
{
	return (_ideas[idx]);
}
