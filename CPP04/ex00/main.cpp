/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:33:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 12:43:08 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    const Animal* meta = new Animal("Animal0");
    const Animal* j = new Dog("Dog0");
    const Animal* i = new Cat("Cat0");

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    Dog dog1;

    Dog dog2("dog2");

    Cat cat1("cat1");

    const Cat cat2;

    cat1 = cat2;    

    return (0);
}