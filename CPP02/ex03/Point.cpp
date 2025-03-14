/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/14 14:58:16 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float& value1, const float& value2) : x(value1), y(value2) {}

/* Point::Point(const Point& object) : x(object.getFloatValue('x')), y(object.getFloatValue('y')) {} */

void    Point::printTriangle(Point const a, Point const b, Point const c, Point const point) const
{
    Fixed tmp1 = y.max(a.y, b.y);
    Fixed tmp2 = y.max(c.y, point.y);
	
    Fixed tmp3 = x.max(a.x, b.x);
    Fixed tmp4 = x.max(c.x, point.x);
    
    Fixed yMax = y.max(tmp1, tmp2);
    Fixed xMax = x.max(tmp3, tmp4);
    
    int y = yMax.toInt() + 1;
    int x = xMax.toInt() + 1;

    char tab[y][x];

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            tab[i][j] = ' ';
    }

    tab[a.y.toInt()][a.x.toInt()] = 'a';
    tab[b.y.toInt()][b.x.toInt()] = 'b';
    tab[c.y.toInt()][c.x.toInt()] = 'c';
    tab[point.y.toInt()][point.x.toInt()] = '.';
    
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            std::cout << tab[i][j];
        std::cout << std::endl;
    }
	std::cout << std::endl;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

Point::~Point(void) {}
