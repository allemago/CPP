/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:03 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/29 14:32:44 by magrabko         ###   ########.fr       */
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

    std::string _target;

/*****************
*     PUBLIC     *
*****************/
public:

//	==================== Canonical Form =========================

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

//	==================== Custom Constructors ====================
	
	PresidentialPardonForm(const std::string&);
	
//	==================== Public Methods =========================

	virtual void	execute(const Bureaucrat&) const;
};
