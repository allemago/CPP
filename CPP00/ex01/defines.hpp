/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:25:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/04 12:27:48 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_HPP
# define DEFINES_HPP

# include <cstring>
# include <iomanip>
# include <iostream>
# include <string>
# include <cstdio>
# include <cstdlib>
# include <cctype>

/* VISUAL */
# define CLEAR_SCREEN "\033[2J\033[1;1H"
# define BOLD "\033[1m"
# define RED    "\033[1;91m"
# define GREEN  "\033[1;92m"
# define BLUE   "\033[1;94m"
# define YELLOW "\033[1;93m"
# define CYAN   "\033[1;96m"
# define MAGENTA "\033[1;95m"
# define WHITE  "\033[1;97m"
# define RESET "\033[0m"


/* MESSAGES */
# define ARG_MSG "Error: try <./phonebook>"
# define MENU_MSG "\n  PHONEBOOK 📲\n"
# define ADD_MSG "  \033[1mAdd a new contact\t\033[0m \033[1;92m[ ADD    ]\033[0m"
# define SEARCH_MSG "  \033[1mFind a contact\t\033[0m \033[1;92m[ SEARCH ]\033[0m"
# define EXIT_MSG "  \033[1mClose the phonebook\t\033[0m \033[1;92m[ EXIT   ]\033[0m\n"
# define ERR_CMD_MSG "  Please enter a valid command.\n"
# define EMPTY_BOOK_MSG "  No contact found: phone book is empty."
# define ALPHA_MSG "  Lowercase or uppercase letter only. Max 20 letters allowed."
# define DIGIT_MSG "  Digits only. Max 20 digits allowed."
# define ASK_INDEX_MSG "\nPlease, select a contact (see index above) for details.\n"
# define ERR_INDEX_MSG "\nChoose a valid index beetween 1 and "
# define EXITING_MSG "  See you soon!\n"

void    handle_eof(void);

#endif
