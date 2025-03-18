/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:36:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/17 18:58:24 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	onVertex(Point const a, Point const b, Point const c, Point const point)
{
	if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
		(point.getX() == b.getX() && point.getY() == b.getY()) ||
		(point.getX() == c.getX() && point.getY() == c.getY()))
		return (true);
	return (false);
}

bool	onEdge(Point const a, Point const b, Point const c, Point const point)
{
	if ((point.getX() >= point.getX().min(a.getX(), b.getX()) &&
		point.getX() <= point.getX().max(a.getX(), b.getX())) ||
		(point.getY() >= point.getY().min(a.getY(), b.getY()) &&
		point.getY() <= point.getY().max(a.getY(), b.getY())))
		return (true);
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (onVertex(a, b, c, point) || onEdge(a, b, c, point))
		return (false);
	
	int aX = a.getXvalue();
	int aY = a.getYvalue();
	
	int bX = b.getXvalue();
	int bY = b.getYvalue();
	
	int cX = c.getXvalue();
	int cY = c.getYvalue();
	
	int pointX = point.getXvalue();
	int pointY = point.getYvalue();
	
	if (aX < 0 || aY < 0 || bX < 0 || bY < 0 || cX < 0 || cY < 0 || pointX < 0 || pointY < 0)
		return (std::cerr << "Error: must be a positive value." << std::endl, false);

	int area1 = pointX * (aY - bY) + (aX * (bY - pointY)) + (bY * (pointY - aY));
	
	int	area2 = pointX * (bY - cY) + (bX * (cY - pointY)) + (cY * (pointY - bY));

	int area3 = pointX * (cY - aY) + (cX * (aY - pointY)) + (aY * (pointY - cY));
	
	a.printTriangle(a, b, c, point);
	if ((area1 < 0 || area2 < 0 || area3 < 0) && (area1 > 0 || area2 > 0 || area3 > 0))
		return (false);
    return (true);
}
