/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:05:25 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 16:12:22 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Data.hpp"
# include <iostream>
# include <stdint.h>

# define BOLD "\033[1m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"

class Serialize
{
/*****************
*    PRIVATE     *
*****************/
private:

	Serialize();
	Serialize(const Serialize&);
	~Serialize();
	Serialize&	operator=(const Serialize&);
	
/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Public Methods =========================

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
