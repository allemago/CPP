/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 17:23:37 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) 
{
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
	Point	P9(4, 4);
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
