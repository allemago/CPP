/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:27:01 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 18:49:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <cerrno>

# define ARG_MSG "./replace [file] [string to replace] [new string]"

class FileEditor
{
	public:
	
	FileEditor(const std::string &inFileName, const std::string &s1, const std::string &s2);
	~FileEditor(void);
	
	int		openFile(void);
	int		editFile(void);
	void	replaceLine(const std::string& line, size_t start);
	
	
	private:
	
	std::ifstream inFile;
	std::ofstream outFile;
	std::string inFileName;
	std::string outFileName;
	std::string s1;
	std::string s2;
};

#endif
