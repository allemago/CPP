/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:03 by magrabko          #+#    #+#             */
/*   Updated: 2025/07/14 13:41:40 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>

# define PARDONED " has been pardoned by Zaphod Beeblebrox."
# define NOT_PARDONED " couldn't be pardoned by "

class PresidentialPardonForm : public AForm
{
/*****************
*     PRIVATE    *
*****************/
private:

	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);
    
/*****************
*     PUBLIC     *
*****************/
public:

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();

//	==================== Public Methods =========================

	virtual void	execute(const Bureaucrat&) const;
};
