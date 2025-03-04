/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:42:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/04 12:36:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

void    handle_eof(void)
{
	if (std::cin.eof())
	{
		std::cout << CLEAR_SCREEN << BOLD "\n" EXITING_MSG RESET << std::endl;
		std::exit(0);
	}
}

int main(int argc, char **argv)
{
    PhoneBook   data;
    
    (void)argv;
    if (argc != 1)
        std::cout << BOLD ARG_MSG RESET << std::endl;
    data.book_prompt();
    return (0);
}
