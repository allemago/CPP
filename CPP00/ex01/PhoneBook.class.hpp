/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:36:47 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/04 13:51:45 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{
  public:

	int			add_count;
	long 		index;
	std::string input;

	PhoneBook(void);
	~PhoneBook(void);

	void		book_prompt(void);
	void		display_commands(void);
	void		search_command(void);
	void		ask_information(int *i);
	void		search_contact(void);
	void		draw_header(void);
	void		get_index(void);
	int			fill_book(void);

  private:
  
	Contact 	contacts[8];
};

#endif
