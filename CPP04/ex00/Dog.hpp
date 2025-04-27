/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:54:33 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 12:31:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

# include <iostream>
# include <iomanip>

class Dog : public Animal
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
    Dog(void);
    Dog(const std::string& name);
    Dog(const Dog& object);
    ~Dog(void);
    
    Dog& operator=(const Dog& object);

    void                makeSound(void) const;
    void                displayStatus(std::string constructor) const;
    const std::string&  getType(void) const;
};
