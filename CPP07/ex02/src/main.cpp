/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:22:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/04 12:29:06 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
    {    
        // test d'init d'un objet de type Array<int>
        std::cout << BOLD "TEST 1" RESET << std::endl;
        Array<int> array(5);
        for (size_t i = 0; i < array.size(); i++)
        {
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        }

        // test d'affichage avec les surcharges << et []
        std::cout << BOLD "\nTEST 2" RESET << std::endl;
        array[2] = 0;
        std::cout << "array[2] = " << array[2] << std::endl;

        // test d'acces avec un index > a la taille de l'array
        std::cout << BOLD "\nTEST 3" RESET << std::endl;
        try
        {
            std::cout << array[10] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        // copie de l'array dans "copy"
        std::cout << BOLD "\nTEST 4" RESET << std::endl;
        Array<int> copy(array);
        copy[0] = 21; // ajout d'un entier
        for (size_t i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
        for (size_t i = 0; i < array.size(); i++)
            std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
        
        // verification de la deep copy
        if (&copy != &array)
            std::cout << YELLOW "\ncopy is a deep copy.\n" RESET << std::endl;
    }

    {
        std::cout << BOLD "TEST 5" RESET << std::endl;
        int *a = new int();
        std::cout << "a = " << *a << std::endl;
        delete a;

        std::cout << BOLD "TEST 6" RESET << std::endl;
        Array<int> *b = new Array<int>();
        std::cout << "b = " << *b << std::endl;
        delete b;
    }

    return (0);
}