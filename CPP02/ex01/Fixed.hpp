/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:27:49 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/18 19:23:47 by magrabko         ###   ########.fr       */
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
	
    Fixed&  operator=(const Fixed& object);

	void	setRawBits(int const raw);
	int		getRawBits(void) const;
	
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& object);

#endif
