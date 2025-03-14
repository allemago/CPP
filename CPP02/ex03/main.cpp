/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/14 15:40:08 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) 
{
/* 	Point A(3, 4);
    Point B(8, 4);
    Point C(2, 2);

    Point P1(4, 3);  // inside
    Point P2(10, 4); // outside
    Point P3(3, 4);  // on vertex -> outside
    Point P4(8, 4);  // on vertex -> outside
    Point P5(2, 2);  // on vertex -> outside
    Point P6(5, 4);  // on edge -> outside
    Point P7(2, 3);  // outside
    Point P8(6, 3);  // inside
    Point P9(0, 0);  // outside
    Point P10(4, 5); // outside */

	Point A(0.5, 0.5);
	Point B(5.5, 0.5);
	Point C(3.5, 4.5);

	Point P1(2.5, 2.5);  // inside
	Point P2(0.5, 0.5);  // on vertex -> outside
	Point P3(5.5, 0.5);  // on vertex -> outside
	Point P4(3.5, 4.5);  // on vertex -> outside
	Point P5(1.0, 1.0);  // inside
	Point P6(4.0, 2.0);  // inside
	Point P7(6.0, 0.5);  // outside
	Point P8(3.0, 3.5);  // inside
	Point P9(2.0, 1.0);  // inside
	Point P10(4.0, 5.5); // outside

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


/* 
int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside1(5.0f, 5.0f);
    Point outside1(10.0f, 10.0f);
    Point vertexA(0.0f, 0.0f);
    Point edgeMidAB(5.0f, 0.0f);
    Point edgeMidBC(7.5f, 5.0f);
    Point edgeMidCA(2.5f, 5.0f);

    Point a2(0.0f, 10.0f);
    Point b2(10.0f, 10.0f);
    Point c2(5.0f, 0.0f);

    Point inside2(5.0f, 5.0f);
    Point outside2(5.0f, -1.0f);

    a.printTriangle(a, b, c, inside1);
    std::cout << "\nPoint is " << (bsp(a, b, c, inside1) ? "inside." : "outside.") << " (Expected: inside)" << std::endl;

    a.printTriangle(a, b, c, outside1);
    std::cout << "\nPoint is " << (bsp(a, b, c, outside1) ? "inside." : "outside.") << " (Expected: outside)" << std::endl;

    a.printTriangle(a, b, c, vertexA);
    std::cout << "\nPoint is " << (bsp(a, b, c, vertexA) ? "inside." : "outside.") << " (Expected: outside)" << std::endl;

    a.printTriangle(a, b, c, edgeMidAB);
    std::cout << "\nPoint is " << (bsp(a, b, c, edgeMidAB) ? "inside." : "outside.") << " (Expected: outside)" << std::endl;

    a.printTriangle(a, b, c, edgeMidBC);
    std::cout << "\nPoint is " << (bsp(a, b, c, edgeMidBC) ? "inside." : "outside.") << " (Expected: outside)" << std::endl;

    a.printTriangle(a, b, c, edgeMidCA);
    std::cout << "\nPoint is " << (bsp(a, b, c, edgeMidCA) ? "inside." : "outside.") << " (Expected: outside)" << std::endl;

    a2.printTriangle(a2, b2, c2, inside2);
    std::cout << "\nPoint is " << (bsp(a2, b2, c2, inside2) ? "inside." : "outside.") << " (Expected: inside)" << std::endl;

    a2.printTriangle(a2, b2, c2, outside2);
    std::cout << "\nPoint is " << (bsp(a2, b2, c2, outside2) ? "inside." : "outside.") << " (Expected: outside)" << std::endl;

    return 0;
} */

/* int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    Point point(5.0f, 5.0f);

    a.printTriangle(a, b, c, point);
    
	std::cout << "\nPoint is " << (bsp(a, b, c, point) ? "inside." : "outside.") << std::endl;

    return (0);
} */
