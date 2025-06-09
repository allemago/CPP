/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:30:25 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/09 17:36:57 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <ctime>

int main(void)
{
    {
        try // shortest span with 10 000 values
        {
            std::cout << BOLD "TEST 1" RESET << std::endl;
            std::srand(std::time(NULL));
            Span distance(10000);
            for (size_t i = 0; i < 10000; i++)
                distance.addNumber(std::rand());
            std::cout << "shortest span is: " << distance.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    {
        try // shortest span
        {
            std::cout << BOLD "\nTEST 2" RESET << std::endl;
            Span distance(10);
            distance.addNumber(50);
            distance.addNumber(500);
            distance.addNumber(550);
            distance.addNumber(600);
            distance.addNumber(650);
            distance.addNumber(92);
            distance.addNumber(700);
            distance.addNumber(750);
            distance.addNumber(90);
            distance.addNumber(800);
            std::cout << "shortest span is: " << distance.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try // longest span with 10 000 values
        {
            std::cout << BOLD "\nTEST 3" RESET << std::endl;
            std::srand(std::time(NULL));
            Span distance(10000);
            for (size_t i = 0; i < 10000; i++)
                distance.addNumber(std::rand());
            std::cout << "longest span is: " << distance.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try // longest span
        {
            std::cout << BOLD "\nTEST 4" RESET << std::endl;
            Span distance(10);
            distance.addNumber(50);
            distance.addNumber(500);
            distance.addNumber(550);
            distance.addNumber(600);
            distance.addNumber(650);
            distance.addNumber(92);
            distance.addNumber(700);
            distance.addNumber(750);
            distance.addNumber(90);
            distance.addNumber(800);
            std::cout << "longest span is: " << distance.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try // longest span with int max and min
        {
            std::cout << BOLD "\nTEST 5" RESET << std::endl;
            Span distance(2);
            distance.addNumber(2147483647);
            distance.addNumber(-2147483648);
            std::cout << "longest span is: " << distance.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    {
        try // adding too many values
        {
            std::cout << BOLD "\nTEST 6" RESET << std::endl;
            Span distance(2);
            distance.addNumber(1);
            distance.addNumber(2);
            distance.addNumber(3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try // not enough values to compute span
        {
            std::cout << BOLD "\nTEST 7" RESET << std::endl;
            Span distance(2);
            distance.addNumber(1);
            std::cout << "longest span is: " << distance.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}
