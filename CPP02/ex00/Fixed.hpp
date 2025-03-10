/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:03:36 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/10 09:56:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstring>
# include <string>

class Fixed
{
  public:

  Fixed(void);
  Fixed(const Fixed &object);
  ~Fixed(void);

  Fixed&    operator=(const Fixed &object);

  int   getRawBits(void) const;
  void  setRawBits(int const raw);
  
  private:

  int   value;
  static const int  bits;
};

#endif
