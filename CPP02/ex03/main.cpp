/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/18 21:01:34 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) 
{
/* 	Point A(3, 4);
    Point B(8, 4);
    Point C(2, 2);

    Point P1(4, 3);
    Point P2(10, 4);
    Point P3(3, 4); 
    Point P4(8, 4); 
    Point P5(2, 2); 
    Point P6(5, 4); 
    Point P7(2, 3); 
    Point P8(6, 3);
    Point P9(0, 0); 
    Point P10(4, 5); 


	Point A(0.5, 0.5);
	Point B(5.5, 0.5);
	Point C(3.5, 4.5);

	Point P1(2.5, 2.5);
	Point P2(0.5, 0.5); 
	Point P3(5.5, 0.5); 
	Point P4(3.5, 4.5); 
	Point P5(1.0, 1.0);
	Point P6(4.0, 2.0);
	Point P7(6.0, 0.5); 
	Point P8(3.0, 3.5);
	Point P9(2.0, 1.0);
	Point P10(4.0, 5.5); 
*/

	Point	A(0, 0);
	Point	B(10, 0);
	Point	C(0, 10);
	
	Point	P1(0, 0);
	Point	P2(10.1, 0);
	Point	P3(0, 10);
	Point	P4(3, 3);
	Point	P5(5.5, 5.5);
	Point	P6(5, 5);
	Point	P7(-1, -1);
	Point	P8(10, 10);
	Point	P9(4.2, 6.8);
	Point	P10(0, 5);

		
	std::cout << "\n____________________________________\n" << std::endl;
    std::cout << "P1 is:\n\n" << ((bsp(A, B, C, P1)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P2 is:\n\n" << ((bsp(A, B, C, P2)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P3 is:\n\n" << ((bsp(A, B, C, P3)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P4 is:\n\n" << ((bsp(A, B, C, P4)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P5 is:\n\n" << ((bsp(A, B, C, P5)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P6 is:\n\n" << ((bsp(A, B, C, P6)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P7 is:\n\n" << ((bsp(A, B, C, P7)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P8 is:\n\n" << ((bsp(A, B, C, P8)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P9 is:\n\n" << ((bsp(A, B, C, P9)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
    std::cout << "P10 is:\n\n" << ((bsp(A, B, C, P10)) ? "inside." : "outside.") << std::endl;
	std::cout << "____________________________________\n" << std::endl;
	
	return (0);
}
