/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:32:29 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/13 19:47:59 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) 
{
	Point A(3, 4);
	Point B(8, 4);
	Point C(2, -2);
	
	Point D(float(4), float(3)); 				// Point inside the triangle
	Point F(float(4), float(4)); 				// Point in the border of the triangle
	Point E(float(4.0183), float(3.9)); 		// Point inside the triangle close to the border
	Point G(float(4.00389), float(4.4035)); 	// Point outside the triangle close to the border
	Point H(float(-4.00389), float(-4.4035)); 	// Point outside the triangle
	Point I(float(2), float(-2)); 				// Point is on the vertex of the triangle


	std::cout << "\n____________________________________" << std::endl;
	
	A.printTriangle(A, B, C, D);
    std::cout << ((bsp(A, B, C, D)) ? "true." : "false.") << std::endl;

	std::cout << "\n____________________________________" << std::endl;
	
    A.printTriangle(A, B, C, F);
    std::cout << ((bsp(A, B, C, F)) ? "true." : "false.") << std::endl;

	std::cout << "\n____________________________________" << std::endl;

    A.printTriangle(A, B, C, E);
    std::cout << ((bsp(A, B, C, E)) ? "true." : "false.") << std::endl;

	std::cout << "\n____________________________________" << std::endl;
	
    A.printTriangle(A, B, C, G);
    std::cout << ((bsp(A, B, C, G)) ? "true." : "false.") << std::endl;

	std::cout << "\n____________________________________" << std::endl;
	
    A.printTriangle(A, B, C, H);
    std::cout << ((bsp(A, B, C, H)) ? "true." : "false.") << std::endl;

	std::cout << "\n____________________________________" << std::endl;

	A.printTriangle(A, B, C, I);
    std::cout << ((bsp(A, B, C, I)) ? "true." : "false.") << std::endl;
	
	std::cout << "\n____________________________________" << std::endl;
	
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
