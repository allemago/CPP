/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:34:19 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/15 16:52:20 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# define BOLD "\033[1m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"

template <typename T>
void iter(const T* array, size_t len, void (*func)(const T&))
{
	if (!array || !func)
		return ;
		
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void    print(const T& p)
{
    std::cout << p << std::endl;
}
