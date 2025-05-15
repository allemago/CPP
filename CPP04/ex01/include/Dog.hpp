/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:33 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 11:44:19 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <iomanip>

class Dog : public Animal
{
/*****************
*     PRIVATE    *
*****************/
private:

    Brain*  _brain;
    
/*****************
*     PUBLIC     *
*****************/
public:

    Dog(void);
    Dog(const std::string name);
    Dog(const std::string idea, const size_t i);
    Dog(const Dog& object);
    ~Dog(void);

    Dog& operator=(const Dog& object);

    void    makeSound(void) const;
    void	printIdea(int idx) const;
    void    displayStatus(std::string constructor) const;
};
