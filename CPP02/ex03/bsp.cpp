/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:36:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/14 15:30:21 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int aX = a.getX().getValue();
	int aY = a.getY().getValue();
	
	int bX = b.getX().getValue();
	int bY = b.getY().getValue();

	int cX = c.getX().getValue();
	int cY = c.getY().getValue();

	int pointX = point.getX().getValue();
	int pointY = point.getY().getValue();
	
	if (aX < 0 || aY < 0 || bX < 0 || bY < 0 || cX < 0 || cY < 0 || pointX < 0 || pointY < 0)
		return (std::cerr << "Error: must be a positive value." << std::endl, false);
	
	int _a = abs((aX * (bY - cY) + bX * (cY - aY) + cX * (aY - bY)));
	
	int _b = abs((pointX * (bY - cY) + bX * (cY - pointY) + cX * (pointY - bY)));
	
	int _c = abs((aX * (pointY - cY) + pointX * (cY - aY) + cX * (aY - pointY)));
	
	int _point = abs((aX * (bY - pointY) + bX * (pointY - aY) + pointX * (aY - bY)));
	
	a.printTriangle(a, b, c, point);
	if (_b == 0 || _c == 0 || _point == 0)
        return (false);
    return (_a == _b + _c + _point);
}
