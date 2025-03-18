/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:36:09 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/18 19:37:27 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	/*************
	 *  PRIVATE  *
	 *************/
	private:

	static const int    _bits;
	int                 _value;
	
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
	
    Fixed 	operator+(const Fixed& right) const;
    Fixed	operator-(const Fixed& right) const;
    Fixed	operator*(const Fixed& right) const;
    Fixed	operator/(const Fixed& right) const;
	
    bool    operator>(const Fixed& right) const;
    bool    operator<(const Fixed& right) const;
    bool    operator>=(const Fixed& right) const;
    bool    operator<=(const Fixed& right) const;
    bool    operator==(const Fixed& right) const;
    bool    operator!=(const Fixed& right) const;
	
    // PREFIXES
    Fixed&	operator++(void);
    Fixed&	operator--(void); 
    // SUFFIXES
    Fixed	operator++(int);
    Fixed	operator--(int);

	void	setRawBits(int const raw);
	int		getRawBits(void) const;

	float	toFloat(void) const;
	int     toInt(void) const;
	
    static Fixed& 		min(Fixed& object1, Fixed& object2);
    static const Fixed& min(const Fixed& object, const Fixed& object2);
	
    static Fixed& 		max(Fixed& object1, Fixed& object2);
    static const Fixed& max(const Fixed& object1, const Fixed& object2);
    
};

std::ostream&	operator<<(std::ostream& os, const Fixed& object);

#endif
