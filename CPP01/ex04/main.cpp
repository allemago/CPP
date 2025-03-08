/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:19:45 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 18:46:03 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << ARG_MSG << std::endl, 1);
	FileEditor editor(argv[1], argv[2], argv[3]);
	if (editor.editFile())
		return (1);
	return (0);
}
