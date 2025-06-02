/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:56:51 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/02 09:44:52 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>

enum e_randomBase
{
	A_BASE = 0,
	B_BASE = 1,
	C_BASE = 2,
};

class Base
{
/*****************
*     PUBLIC     *
*****************/
public:

	virtual ~Base();
};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);
