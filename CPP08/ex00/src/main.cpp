/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:40:31 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/05 15:21:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    {
        try
        {
            std::cout << BOLD "TEST 1" RESET << std::endl;
            std::vector<int> values;
            values.push_back(1), values.push_back(2), values.push_back(3);
            std::cout << *::easyfind(values, 1) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    {
        try
        {
            std::cout << BOLD "\nTEST 2" RESET << std::endl;
            std::list<int> values;
            values.push_back(4), values.push_back(5), values.push_back(6);
            std::cout << *::easyfind(values, 5) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    {
        try
        {
            std::cout << BOLD "\nTEST 3" RESET << std::endl;
            std::deque<int> values;
            values.push_back(7), values.push_back(8), values.push_back(9);
            std::cout << *::easyfind(values, 9) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

        {
        try
        {
            std::cout << BOLD "\nTEST 4" RESET << std::endl;
            std::deque<int> values;
            values.push_back(10), values.push_back(11), values.push_back(12);
            std::cout << *::easyfind(values, 1) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    return (0);
}
