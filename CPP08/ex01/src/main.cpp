/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:30:25 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/09 13:12:56 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main(void)
{
    try
    {
        Span distance(100000);
        distance.addNumbers(50);
        distance.addNumbers(5963);
        distance.addNumbers(12);
        distance.addNumbers(5);
        distance.addNumbers(32);
        std::cout << "longest span is: " << distance.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
