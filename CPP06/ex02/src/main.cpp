/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:16:42 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 10:10:32 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

int main(void)
{
	srand(time(NULL));
	
    Base *first = generate();
	std::cout << "first type is ";
	identify(first);
	std::cout << "*first type is ";
    identify(*first);
	std::cout << std::endl;
	
	Base *second = generate();
	std::cout << "second type is ";
    identify(second);
	std::cout << "*second type is ";
    identify(*second);
	std::cout << std::endl;
	
	Base *third = generate();
	std::cout << "third type is ";
	identify(third);
	std::cout << "*third type is ";
    identify(*third);

	delete first;
	delete second;
	delete third;

    return (0);
}
