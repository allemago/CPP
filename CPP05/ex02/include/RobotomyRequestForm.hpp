/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:05 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 12:32:30 by magrabko         ###   ########.fr       */
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

    std::string _target;

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
