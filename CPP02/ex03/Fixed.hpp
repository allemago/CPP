/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:36:09 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/13 18:06:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed
{
    /************
     *  PUBLIC  *
     ************/
    public:

    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& object);
    ~Fixed(void);

    Fixed&  operator=(const Fixed& right);
    
    Fixed operator+(const Fixed& right);
    Fixed operator-(const Fixed& right);
    Fixed operator*(const Fixed& right);
    Fixed operator/(const Fixed& right);

    bool    operator>(const Fixed& right);
    bool    operator<(const Fixed& right);
    bool    operator>=(const Fixed& right);
    bool    operator<=(const Fixed& right);
    bool    operator==(const Fixed& right);
    bool    operator!=(const Fixed& right);

    /* PREFIXES */
    Fixed& operator++(void);
    Fixed& operator--(void); 
    /* SUFFIXES */
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed& min(Fixed& object1, Fixed& object2);
    static const Fixed& min(const Fixed& object, const Fixed& object2);

    static Fixed& max(Fixed& object1, Fixed& object2);
    static const Fixed& max(const Fixed& object1, const Fixed& object2);
    
    float   returnFloatValue(void) const;
    int     returnIntValue(void) const;
    float   toFloat(void) const;
    int     toInt(void) const;
    
    /*************
     *  PRIVATE  *
     *************/
    private:

    int                 value;
    static const int    bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& object);

#endif
