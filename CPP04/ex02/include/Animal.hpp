/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:42:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 10:47:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

class Animal
{
/*****************
*   PROTECTED    *
*****************/
protected:
    
    std::string _type;
    
/*****************
*     PUBLIC     *
*****************/
public:
    
    Animal(void);
    Animal(const std::string name);
    Animal(const Animal& object);
    virtual ~Animal(void);
    
    Animal& operator=(const Animal& object);

    const std::string&  getType(void) const;
    virtual void        makeSound(void) const = 0;
};
