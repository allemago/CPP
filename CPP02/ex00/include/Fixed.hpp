/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:03:36 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/04 10:00:55 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstring>
# include <string>

class Fixed
{
/*****************
*    PRIVATE     *
*****************/
private:
	
	static const int	_bits;
	int   				_value;
	
/*****************
*     PUBLIC     *
*****************/
public:

	Fixed(void);
	Fixed(const Fixed& object);
	~Fixed(void);

	Fixed&	operator=(const Fixed& object);

	void	setRawBits(int const raw);
	int		getRawBits(void) const;
};

#endif
