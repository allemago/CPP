/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:19:45 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 17:47:10 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	FileEditor editor;
	
	if (argc != 4)
		return (std::cerr << ARG_MSG << std::endl, 1);
	editor.inFileName = argv[1];
	editor.s1 = argv[2];
	editor.s2 = argv[3];
	if (editor.editFile())
		return (1);
	return (0);
}
