/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:46:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 09:54:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "WrongAnimal.hpp"
# include <iostream>
# include <iomanip>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

class WrongCat : public WrongAnimal
{
/*****************
*     PUBLIC     *
*****************/
public:

    WrongCat(void);
    WrongCat(const std::string name);
    WrongCat(const WrongCat& object);
    ~WrongCat(void);

    WrongCat& operator=(const WrongCat& object);

    void    makeSound(void) const;
    void    displayStatus(std::string constructor) const;
};
