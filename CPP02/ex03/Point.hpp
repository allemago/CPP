/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:59 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/14 14:58:07 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	/************
     *  PUBLIC  *
     ************/
    public:

    Point(void);
    Point(const float& value1, const float& value2);
	/*Point(const Point& object);*/
	~Point(void);

    Point&  operator=(const Point& right);

	Fixed	getX(void) const;
    Fixed	getY(void) const;

    void    printTriangle(Point const a, Point const b, Point const c, Point const point) const;

	/*************
     *  PRIVATE  *
     *************/
    private:

    Fixed const x;
    Fixed const y;
};

std::ostream&   operator<<(std::ostream& os, const Point& object);
bool	        bsp(Point const a, Point const b, Point const c, Point const point);

#endif
