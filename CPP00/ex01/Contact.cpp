/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:08:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 22:22:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

bool Contact::is_number_valid(std::string& number)
{
	int i;
	
	if (number.size() > 20)
		return false;
	for (i = 0; number[i]; i++)
	{
		if (!std::isdigit(number[i]))
			return false;
	}
	return true;
}

void Contact::get_phone_number(std::string& number, std::string msg)
{
	while (1)
	{
		std::cout << BOLD << msg << RESET;
		if (!std::getline(std::cin, number))
		{
			handle_eof();
			std::cin.clear();
			continue;
		}
		std::cout << CLEAR_SCREEN << std::endl;
		if (number.empty())
		{
			std::cout << YELLOW DIGIT_MSG RESET << std::endl;
			continue;
		}
		if (is_number_valid(number) == false)
		{
			std::cout << YELLOW DIGIT_MSG RESET << std::endl;
			continue;
		}
		break ;
	}
}

int Contact::epur_name(std::string& details)
{
	std::string tmp;
	int			i;
	int			start = 0;
	
	while (details[start] && std::isspace(details[start]))
		start++;
	if (details[start] == '\0')
		return (0);
	details = &details[start];
	for (i = details.size() - 1; i > 0 && std::isspace(details[i]); i--);
	details.resize(i + 1);
	for (start = 0; details[start]; start++)
	{
		if (std::isspace(details[start]))
			continue;
		tmp = tmp + details[start];
		if (details[start + 1] != '\0' && std::isspace(details[start + 1]))
			tmp = tmp + ' ';
	}
	details = tmp;
	return (1);
}

bool Contact::is_name_valid(std::string& details)
{
	int i;

	if (details.size() > 20)
		return false;
	for (i = 0; details[i]; i++)
	{
		if (!std::isalpha(details[i]) && !std::isspace(details[i]))
			return false;
	}
	if (!epur_name(details))
		return false;
	return true;
}

void Contact::get_information(std::string& details, std::string msg)
{
	while (1)
	{
		std::cout << BOLD << msg << RESET;
		if (!std::getline(std::cin, details))
		{
			handle_eof();
			std::cin.clear();
			continue;
		}
		std::cout << CLEAR_SCREEN << std::endl;
		if (details.empty())
		{
			std::cout << YELLOW ALPHA_MSG RESET << std::endl;
			continue ;
		}
		if (is_name_valid(details) == false)
		{
			std::cout << YELLOW ALPHA_MSG RESET << std::endl;
			details.clear();
			continue;
		}
		break ;
	}
}

Contact Contact::fill_information(void)
{
	Contact new_contact;
	
	get_information(new_contact.FirstName, "\nFirst name: ");
	get_information(new_contact.LastName, "\nLast name: ");
	get_information(new_contact.NickName, "\nNickname: ");
	get_information(new_contact.DarkestSecret, "\nDarkest secret: ");
	get_phone_number(new_contact.PhoneNumber, "\nPhone number: ");
	return (new_contact);
}

void Contact::display_index(Contact contact, int i)
{
	std::string tmp;
	
	std::cout << "|" << std::setfill(' ') << std::setw(10) << std::right << i + 1 << "|";
	check_size(contact.FirstName, tmp);
	std::cout << std::setw(10) << std::right << tmp << "|";
	check_size(contact.LastName, tmp);
	std::cout << std::setw(10) << std::right << tmp << "|";
	check_size(contact.NickName, tmp);
	std::cout << std::setw(10) << std::right << tmp << "|" << std::endl;
}

void Contact::check_size(std::string& details, std::string& tmp)
{
	if (details.size() > 10)
	{
		tmp = details.substr(0, 10);
		tmp[9] = '.';
	}
	else
		tmp = details;
}

void Contact::clear_contact(Contact contact)
{
	contact.FirstName.clear();
	contact.LastName.clear();
	contact.NickName.clear();
	contact.PhoneNumber.clear();
	contact.DarkestSecret.clear();
}

Contact Contact::fill_all_information(void)
{
	Contact new_contact;
	static char	c = 'a';
	
	if (c == 'i')
		c = 'a';
	new_contact.FirstName = &c;
	new_contact.LastName = &c;
	new_contact.NickName = &c;
	new_contact.DarkestSecret = &c;
	new_contact.PhoneNumber = c;
	c++;
	return (new_contact);
}
