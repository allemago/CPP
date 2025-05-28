/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 10:54:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>

class RobotomyRequestForm : public AForm
{
/*****************
*     PUBLIC     *
*****************/
public:

//	==================== Canonical Form =========================

	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

//	==================== Public Methods =========================

	virtual void	execute(const Bureaucrat&) const;
};
