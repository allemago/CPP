/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:55:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 11:44:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <iomanip>

class Cat : public Animal
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

    Cat(void);
    Cat(const std::string name);
    Cat(const std::string idea, const size_t i);
    Cat(const Cat& object);
    ~Cat(void);

    Cat& operator=(const Cat& object);

    void    makeSound(void) const;
    void	printIdea(int idx) const;
    void    displayStatus(std::string constructor) const;
};
