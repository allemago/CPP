/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:46:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 09:53:46 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

class WrongAnimal
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
    
    WrongAnimal(void);
    WrongAnimal(const std::string name);
    WrongAnimal(const WrongAnimal& object);
    virtual ~WrongAnimal(void);

    WrongAnimal& operator=(const WrongAnimal& object);

    const std::string&  getType(void) const;
    void                makeSound(void) const;
};
