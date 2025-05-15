/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:33:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:03:30 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

/* int main(void)
{
    const WrongAnimal* meta = new WrongAnimal("WRONG_ANIMAL");
    meta->makeSound();
    delete meta;

    const WrongAnimal* i = new WrongCat("WRONG_CAT");
    i->makeSound();
    delete i;
    
    return (0);
} */

int main(void)
{
    const Animal* a = new Animal();
    a->makeSound();
    
    const Animal* b = new Dog();
    b->makeSound();
    
    const Animal* c = new Cat();
    c->makeSound();

    delete a;
    delete b;
    delete c;

    const Dog e;
    e.makeSound();

    const Dog d(e);
    d.makeSound();

    const Cat g;
    g.makeSound();

    Cat h;
    h.makeSound();

    h = g;
    h.makeSound();

    return (0);
}
