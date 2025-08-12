/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:46:51 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/15 16:48:38 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int main(void)
{
    std::cout << BOLD "TEST 1 - const string array[4]" RESET << std::endl;
    const std::string array1[4] = {"coucou", "bonjour", "salut", "hello"};
    iter(array1, sizeof(array1) / sizeof(array1[0]), print);

    std::cout << BOLD "\nTEST 2 - string array[4]" RESET << std::endl;
    std::string array2[4] = {"coucou", "bonjour", "salut", "hello"};
    iter(array2, sizeof(array2) / sizeof(array2[0]), print);

    std::cout << BOLD "\nTEST 3 - char *array[4]" RESET << std::endl;
    char str[3] = "hi";
    char *array3[4] = {str, str, str, str};
    iter(array3, sizeof(array3) / sizeof(array3[0]), print);

    std::cout << BOLD "\nTEST 4 - const char *array[4]" RESET << std::endl;
    const char *array4[4] = {"coucou", "bonjour", "salut", "hello"};
    iter(array4, sizeof(array4) / sizeof(array4[0]), print);

    std::cout << BOLD "\nTEST 5 - const char array[5]" RESET << std::endl;
    const char array5[4] = {'a', 'b', 'c', 'd'};
    iter(array5, sizeof(array5) / sizeof(char), print);

    std::cout << BOLD "\nTEST 6 - int array[4]" RESET << std::endl;
    int array6[4] = {1, 2, 3, 4};
    iter(array6, sizeof(array6) / sizeof(array6[0]), print);

    std::cout << BOLD "\nTEST 7 - const int array[4]" RESET << std::endl;
    const int array7[4] = {1, 2, 3, 4};
    iter(array7, sizeof(array7) / sizeof(array7[0]), print);

    {
        int tab[] = {0, 1, 2, 3, 4};
        int tab2[5][5];

        iter(tab, sizeof(tab) / sizeof(tab[0]), print<const int>);
        std::cout << "\n" << std::endl;
        iter(*tab2, sizeof(tab2) / sizeof(tab2[0]), print<int>);
    }
    
    return (0);
}
