/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:16:03 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/28 10:54:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm
{
/*****************
*     PUBLIC     *
*****************/
public:

//	==================== Canonical Form =========================

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

//	==================== Public Methods =========================

	virtual void	execute(const Bureaucrat&) const;
};
