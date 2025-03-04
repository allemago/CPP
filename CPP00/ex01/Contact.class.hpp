/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:07:58 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/04 12:57:37 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "defines.hpp"

class Contact
{
  public:

	Contact	fill_information(void);
	Contact fill_all_information(void);
	void	get_information(std::string& details, std::string msg);
	void	get_phone_number(std::string& number, std::string msg);
	void	clear_contact(Contact contact);
	void	display_index(Contact contact, int i);
	void	check_size(std::string& details, std::string& tmp);
	bool	is_name_valid(std::string& str);
	bool	is_number_valid(std::string& str);
	int		epur_name(std::string& details);

  private:

	std::string	FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

#endif
