/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/04 10:34:19 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float& value1, const float& value2) : x(value1), y(value2) {}

Point::Point(const Point& object) : x(object.x), y(object.y) {}

Point::~Point(void) {}

Point&  Point::operator=(const Point& right)
{
    if (&right != this)
        std::cerr << "Error: cannot assign objects with const members." << std::endl;
    return (*this);
}

bool    Point::operator==(const Point& right)
{
    return (this->x.getRawBits() == right.x.getRawBits() && this->y.getRawBits() == right.y.getRawBits());
}

Fixed  Point::getX(void) const
{
    return (this->x);
}

Fixed  Point::getY(void) const
{
    return (this->y);
}

void    Point::printTriangle(Point const a, Point const b, Point const c, Point const point) const
{
    Fixed xMax;
    Fixed yMax;

    x.max(a.x, b.x) > x.max(c.x, point.x) ?
    (xMax = x.max(a.x, b.x)) : (xMax = x.max(c.x, point.x));
    
    y.max(a.y, b.y) > y.max(c.y, point.y) ?
    (yMax = y.max(a.y, b.y)) : (yMax = y.max(c.y, point.y));
    
    int x = xMax.toInt() + 1;
    int y = yMax.toInt() + 1;

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
