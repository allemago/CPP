/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/13 16:51:24 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float& value1, const float& value2) : x(value1), y(value2) {}

/* Point::Point(const Point& object) : x(object.getFloatValue('x')), y(object.getFloatValue('y')) {} */

void    Point::printTriangle(Point const a, Point const b, Point const c, Point const point)
{
    Fixed tmp1 = x.max(a.x, b.x);
    Fixed tmp2 = x.max(c.x, point.x);

    Fixed tmp3 = y.max(a.y, b.y);
    Fixed tmp4 = y.max(c.y, point.y);
    
    Fixed xMax = x.max(tmp1, tmp2);
    Fixed yMax = y.max(tmp1, tmp2);
    
    int x = xMax.returnIntValue() + 1;
    int y = yMax.returnIntValue() + 1;

    char tab[y][x];

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            tab[i][j] = ' ';
    }

    tab[a.y.returnIntValue()][a.x.returnIntValue()] = 'a';
    tab[b.y.returnIntValue()][b.x.returnIntValue()] = 'b';
    tab[c.y.returnIntValue()][c.x.returnIntValue()] = 'c';
    tab[point.y.returnIntValue()][point.x.returnIntValue()] = '.';
    
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            std::cout << tab[i][j];
        std::cout << std::endl;
    }
}

Point::~Point(void) {}

/* 

    OUTILS:

    ->  pow(x, y);
    ->  sqrt(x);

*/
