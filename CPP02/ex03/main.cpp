/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/13 16:51:02 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    Point point(5.0f, 5.0f);

    a.printTriangle(a, b, c, point);
    
/*  std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl; */

    return (0);
}
