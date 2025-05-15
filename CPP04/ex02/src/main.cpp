/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:33:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 13:17:48 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

void deepCopyTest()
{
	std::cout << BOLD "\nDEEP COPY TEST\n" RESET << std::endl;

	Dog* dog = new Dog();
	Dog* copyDog = new Dog(*dog);

	std::cout << "dog address: " << &dog << std::endl;
	std::cout << "copyDog address: " << &copyDog << std::endl;

    if (dog != copyDog)
        std::cout << "✅ copyDog is a deep copy" << std::endl;

    delete dog;
    delete copyDog;

    std::cout << std::endl;
}

int main()
{ 
    /* const Animal* test = new Animal; */

    Animal** tab = new Animal*[4];
    
    tab[0] = new Dog();
    std::cout << YELLOW << tab[0]->getType() << " " << RESET;
    tab[0]->printIdea(0);
    std::cout << std::endl;

    tab[1] = new Dog("*i'm gonna eat*", 101);
    std::cout << YELLOW << tab[1]->getType() << " " << RESET;
    tab[1]->printIdea(101);
    std::cout << std::endl;

    tab[2] = new Cat("*i should find a mouse for lunch*", 18);
    std::cout << YELLOW << tab[2]->getType() << " " << RESET;
    tab[2]->printIdea(18);
    std::cout << std::endl;
    
    tab[3] = new Cat("*i'm sleepy*", 99);
    std::cout << YELLOW << tab[3]->getType() << " " << RESET;
    tab[3]->printIdea(99);
    std::cout << std::endl;
    
    for (int i = 0; i < 4; i++)
        delete tab[i];
    delete[] tab;

    std::cout << std::endl;
    deepCopyTest();
    
    return (0);
}
