/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:36:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/13 19:52:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float aX = a.getX().returnFloatValue();
	float aY = a.getY().returnFloatValue();
	
	float bX = b.getX().returnFloatValue();
	float bY = b.getY().returnFloatValue();

	float cX = c.getX().returnFloatValue();
	float cY = c.getY().returnFloatValue();

	float pointX = point.getX().returnFloatValue();
	float pointY = point.getY().returnFloatValue();
	
	if (aX < 0 || aY < 0 || bX < 0 || bY < 0 || cX < 0 || cY < 0 || pointX < 0 || pointY < 0)
		return (std::cerr << "Error: must be a positive value." << std::endl, false);
	
	float _a = fabs((aX * (bY - cY) + bX * (cY - aY) + cX * (aY - bY)) / 2.0);
	
	float _b = fabs((pointX * (bY - cY) + bX * (cY - pointY) + cX * (pointY - bY)) / 2.0);
	
	float _c = fabs((aX * (pointY - cY) + pointX * (cY - aY) + cX * (aY - pointY)) / 2.0);
	
	float _point = fabs((aX * (bY - pointY) + bX * (pointY - aY) + pointX * (aY - bY)) / 2.0);
	
	a.printTriangle(a, b, c, point);
    return (_a == _b + _c + _point);
}
