/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:34:19 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/03 17:20:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void iter(const T* array, size_t len, void (*func)(const T&))
{
	if (!array || !func)
		return ;
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}
