/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:33:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/07 14:29:08 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Wrong.hpp"
#include "../include/Brain.hpp"

void deepCopyTest()
{
	std::cout << BOLD "\nDEEP COPY TEST\n" RESET << std::endl;

	Dog dog;
	Dog copyDog = dog;

	std::cout << "dog address: " << &dog << std::endl;
	std::cout << "copyDog address: " << &copyDog << std::endl;

    std::cout << BOLD "\nEND OF DEEP COPY TEST\n" RESET << std::endl;
}

int main()
{
    /* const Animal* test = new Animal; // can't instantiate an abstract class */

    deepCopyTest();
    std::cout << std::endl;
    
    const Animal* j = new Dog;
    j->makeSound();
    delete j;
    std::cout << std::endl;

    const Animal* i = new Cat;
    i->makeSound();
    delete i;
    std::cout << std::endl;
    
    Animal** tab = new Animal*[4];
    
    tab[0] = new Dog("*i'm craving a bone*", 2);
    std::cout << YELLOW "Animal 1 " RESET;
    tab[0]->makeSound();
    std::cout << std::endl;

    tab[1] = new Dog("*i'm gonna eat*", 0);
    std::cout << YELLOW "Animal 2 " RESET;
    tab[1]->makeSound();
    std::cout << std::endl;

    tab[2] = new Cat("*i should find a mouse for lunch*", 18);
    std::cout << YELLOW "Animal 3 " RESET;
    tab[2]->makeSound();
    std::cout << std::endl;
    
    tab[3] = new Cat("*i'm sleepy*", 99);
    std::cout << YELLOW "Animal 4 " RESET;
    tab[3]->makeSound();
    std::cout << std::endl;
    
    for (int i = 0; i < 4; i++)
        delete tab[i];
    delete[] tab;
    
    return (0);
}
