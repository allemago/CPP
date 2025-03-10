/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:27:49 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/10 15:43:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstring>
# include <string>
#include <variant>
# include <cmath>

class Fixed
{
    public:

    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& object);
    ~Fixed(void);

    Fixed&  operator=(const Fixed& object);
    friend  std::ostream& operator<<(std::ostream& os, const Fixed& object);

    float   toFloat(void) const;
    int     toInt(void) const;
    
    private:

    int                 value;
    static const int    bits;
};

#endif
