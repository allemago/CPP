/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:20:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/03 15:32:07 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void swap(T& x, T& y)
{
	T t;
	t = x;
    x = y;
	y = t;
}

template <typename T>
const T& min(const T& x, const T& y)
{
    return (x < y) ? x : y;
}

template <typename T>
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
}
