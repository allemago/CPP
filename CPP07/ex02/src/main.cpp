/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:22:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/04 15:33:11 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

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
                    std::cout << "arrayInt[" << i << "] = " << "[0]" << std::endl;
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
            {
                if (arrayStr[i].empty())
                    std::cout << "arrayStr[" << i << "] = " << "[NULL]" << std::endl;
            }
            std::cout << std::endl;
            arrayStr[0] = "hello";
            arrayStr[1] = "world";
            for (size_t i = 0; i < arrayStr.size(); i++)
            {
                if (arrayStr[i].empty())
                    std::cout << "arrayStr[" << i << "] = " << "[NULL]" << std::endl;
                else
                    std::cout << "arrayStr[" << i << "] = " << "[" << arrayStr[i] << "]" << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}
