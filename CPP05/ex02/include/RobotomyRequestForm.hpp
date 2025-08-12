/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 13:41:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

# define ROBOTOMY_SUCCESS " has been robotomized successfully!"
# define ROBOTOMY_FAILED "Makes some drilling noises... robotomy failed on "

class RobotomyRequestForm : public AForm
{
/*****************
*     PRIVATE    *
*****************/
private:

	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

/*****************
*     PUBLIC     *
*****************/
public:

	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm();

//	==================== Public Methods =========================

	virtual void	execute(const Bureaucrat&) const;
};
