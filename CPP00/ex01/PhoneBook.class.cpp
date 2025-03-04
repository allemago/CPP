/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:07:52 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/04 13:52:45 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	add_count = 0;
	index = 0;
}

void PhoneBook::display_commands(void)
{
	std::cout << "\n" << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << CYAN MENU_MSG RESET << std::endl;
	std::cout << ADD_MSG << std::endl;
	std::cout << SEARCH_MSG << std::endl;
	std::cout << EXIT_MSG << std::endl;
	std::cout << std::setw(45) << "-\n" << std::endl << BOLD "-> " RESET;
}

void PhoneBook::book_prompt(void)
{
	display_commands();
	while (1)
	{
		if (!std::getline(std::cin, input))
		{
			handle_eof();
			std::cin.clear();
			continue;
		}
		if (!input.compare(0, 5, "EXIT"))
		{
			std::cout << CLEAR_SCREEN << std::endl;
			break ;
		}
		std::cout << CLEAR_SCREEN << std::endl;
		search_command();
	}
}

void PhoneBook::search_command(void)
{
	static int i = 0;
	
	if (input.compare(0, 4, "ADD") == 0)
	{
		ask_information(&i);
	}
	else if (input.compare(0, 7, "SEARCH") == 0)
	{
		search_contact();
	}
	else if (input.compare(0, 8, "ADD_ALL") == 0)
	{
		i = fill_book();
	}
	else
	{
		std::cout << RED ERR_CMD_MSG RESET;
	}
	display_commands();
}

void PhoneBook::ask_information(int *i)
{
	if (*i > 7)
	{
		*i = 0;
	}
	contacts->clear_contact(contacts[*i]);
	contacts[*i] = contacts->fill_information();
	(*i)++;
	if (add_count < 8)
	{
		add_count++;
	}
}

void PhoneBook::search_contact(void)
{
	if (add_count == 0)
	{
		std::cout << CYAN EMPTY_BOOK_MSG RESET << std::endl;
		return ;
	}
	draw_header();
	for (int i = 0; i < add_count; i++)
	{
		contacts->display_index(contacts[i], i);
	}
	std::cout << std::setfill('*') << std::setw(45) << "*" << std::endl;
	std::cout << BOLD ASK_INDEX_MSG RESET << "\n-> ";
	get_index();
	draw_header();
	contacts->display_index(contacts[index - 1], index - 1);
	std::cout << std::setfill('*') << std::setw(45) << "*" << std::endl;
}

void PhoneBook::draw_header(void)
{
	std::cout << std::setfill('*') << std::setw(45) << "*" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First name" << "|";
	std::cout << std::setw(10) << std::right << "Last name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << std::setfill('*') << std::setw(45) << "*" << std::endl;
}

void PhoneBook::get_index(void)
{
	while (1)
	{
		if (!std::getline(std::cin, input))
		{
			handle_eof();
			std::cin.clear();
			continue;
		}
		if (input.empty())
		{
			std::cout << YELLOW ERR_INDEX_MSG << add_count << ".\n" RESET << std::endl << "-> ";
			continue;
		}
		if ((index = std::atol(input.c_str())) <= 0 || index > add_count)
		{
			std::cout << YELLOW ERR_INDEX_MSG << add_count << ".\n" RESET << std::endl << "-> ";
			continue;
		}
		if (!input.empty())
		{
			std::cout << CLEAR_SCREEN << std::endl;
			break ;
		}
		else
			std::cout << RED ERR_CMD_MSG RESET << std::endl;
	}
}

int PhoneBook::fill_book(void)
{
	for (int i = 0; i < 8; i++)
	{
		contacts->clear_contact(contacts[i]);
		contacts[i] = contacts->fill_all_information();
	}
	add_count = 8;
	return (0);
}

PhoneBook::~PhoneBook(void)
{
	std::cout << BOLD EXITING_MSG RESET << std::endl;
}
