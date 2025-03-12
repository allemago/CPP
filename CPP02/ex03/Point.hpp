/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:59 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/12 15:45:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    public:

    Point(void);
    Point(const float& value1, const float& value2);
    Point(const Point& object);
    ~Point(void);

    Point&  operator=(const Point& right);

    private:

    Fixed const x;
    Fixed const y;
    int         pos;
};

#endif
