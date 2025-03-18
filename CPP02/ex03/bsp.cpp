/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:36:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/18 19:17:06 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	area(Point const p1, const Point p2, const Point p3)
{
	return ((p1.getX() - p3.getX()) * 
			(p2.getY() - p3.getY()) - 
			(p2.getX() - p3.getX()) * 
			(p1.getY() - p3.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area1(area(point, a, b));
	Fixed	area2(area(point, b, c));
	Fixed	area3(area(point, c, a));
	
	a.printTriangle(a, b, c, point);
    return ((area1 < 0 && area2 < 0 && area3 < 0) ||
			(area1 > 0 && area2 > 0 && area3 > 0));
}
