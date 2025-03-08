/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:27:01 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 15:33:37 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <cerrno>

# define ARG_MSG "usage: ./replace [file] [old line] [new line]"

class FileEditor
{
	public:

	FileEditor(void);
	~FileEditor(void);
	
	std::string fileName;
	std::string s1;
	std::string s2;
	
	int openFile(void);
	int replaceLines(void);
	
	private:
	
	std::ifstream inFile;
	std::ofstream outFile;
};

#endif
