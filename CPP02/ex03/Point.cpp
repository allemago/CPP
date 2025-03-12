/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/12 16:07:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0), pos(0) {}

Point::Point(const float& value1, const float& value2) : x(value1), y(value2) {}

Point::Point(const Point& object) {}

Point&  Point::operator=(const Point& right)
{
    if (this != &right)
    {
        this->pos = right.pos;
    }
}

Point::~Point(void) {}
