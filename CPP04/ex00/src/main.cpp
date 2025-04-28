/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:33:53 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 11:49:03 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    const Animal* a = new Animal();
    a->makeSound();
    
    const Animal* b = new Dog();
    b->makeSound();
    
    const Animal* c = new Cat();
    c->makeSound();

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

    delete a;
    delete b;
    delete c;

    return (0);
}
