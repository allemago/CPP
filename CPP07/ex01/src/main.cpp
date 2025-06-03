/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:46:51 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/03 17:21:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

template <typename T>
void    print(const T& p)
{
    std::cout << p << std::endl;
}

int main(void)
{
    std::cout << "TEST 1" << std::endl;
    const std::string array1[4] = {"coucou", "bonjour", "salut", "hello"};
    ::iter(array1, sizeof(array1) / sizeof(array1[0]), print);
    std::cout << std::endl;

    std::cout << "TEST 2" << std::endl;
    std::string array2[4] = {"coucou", "bonjour", "salut", "hello"};
    ::iter(array2, sizeof(array2) / sizeof(array2[0]), print);
    std::cout << std::endl;

    std::cout << "TEST 3" << std::endl;
    const char *array3[4] = {"coucou", "bonjour", "salut", "hello"};
    ::iter(array3, sizeof(array3) / sizeof(array3[0]), print);
    std::cout << std::endl;

    std::cout << "TEST 4" << std::endl;
    const char array4[4] = {'a', 'b', 'c', 'd'};
    ::iter(array4, sizeof(array4) / sizeof(char), print);
    std::cout << std::endl;

    std::cout << "TEST 5" << std::endl;
    int array5[4] = {1, 2, 3, 4};
    ::iter(array5, sizeof(array5) / sizeof(array5[0]), print);
    std::cout << std::endl;

    std::cout << "TEST 6" << std::endl;
    const int array6[4] = {1, 2, 3, 4};
    ::iter(array6, sizeof(array6) / sizeof(array6[0]), print);
    std::cout << std::endl;
    
    return (0);
}
