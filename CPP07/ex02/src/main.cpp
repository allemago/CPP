/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:22:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/15 15:14:37 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cmath>
#define MAX_VAL 750

int	main()
{
    {
        Array<int> arrayInt(5);
        
        // test d'init d'un objet de type Array<int>
        std::cout << BOLD "TEST 1" RESET << std::endl;
        try
        {
            for (size_t i = 0; i < arrayInt.size(); i++)
            {
                if (!arrayInt[i])
                    std::cout << "arrayInt[" << i << "] = [" << arrayInt[i] << "]" << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        // test d'acces avec un index > a la taille de l'array
        std::cout << BOLD "\nTEST 2" RESET << std::endl;
        try
        {
            std::cout << arrayInt[10] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        // copie d'array dans copy
        std::cout << BOLD "\nTEST 3" RESET << std::endl;
        try
        {
            for (size_t i = 0; i < arrayInt.size(); i++)
                arrayInt[i] = 42;
            for (size_t i = 0; i < arrayInt.size(); i++)
                std::cout << "arrayInt[" << i << "] = " << "[" << arrayInt[i] << "]" << std::endl;
            Array<int> copy(arrayInt);
            copy[0] = 21;
            std::cout << std::endl;
            
            for (size_t i = 0; i < arrayInt.size(); i++)
                std::cout << "copy[" << i << "] = " << "[" << copy[i] << "]" << std::endl;
            
            // verification de la deep copy
            if (&copy != &arrayInt)
                std::cout << YELLOW "\ncopy is a deep copy." RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    {
        // test d'init d'un type Array<std::string>
        std::cout << BOLD "\nTEST 4" RESET << std::endl;
        try
        {
            Array<std::string> arrayStr(10);
            for (size_t i = 0; i < arrayStr.size(); i++)
                std::cout << "arrayStr[" << i << "] = [" << arrayStr[i] << "]" << std::endl;
            std::cout << std::endl;
            
            arrayStr[0] = "hello";
            arrayStr[1] = "world";
            arrayStr[9] = "!!!!";
            for (size_t i = 0; i < arrayStr.size(); i++)
                std::cout << "arrayStr[" << i << "] = " << "[" << arrayStr[i] << "]" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // MAIN FROM SUBJECT
    std::cout << BOLD "\nMAIN TEST FROM SUBJECT" RESET << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }

    return (0);
}
