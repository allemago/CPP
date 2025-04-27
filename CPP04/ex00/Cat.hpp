/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:55:00 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 12:31:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include <iostream>
# include <iomanip>

class Cat : public Animal
{
    /*************
     * PROTECTED *
     *************/
    protected:
    std::string _type;
    
    /************
     *  PUBLIC  *
     ************/
    public:
    Cat(void);
    Cat(const std::string& name);
    Cat(const Cat& object);
    ~Cat(void);
    
    Cat& operator=(const Cat& object);

    void                makeSound(void) const;
    void                displayStatus(std::string constructor) const;
    const std::string&  getType(void) const;
};
