/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:27:01 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 12:43:14 by magrabko         ###   ########.fr       */
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
	/*************
     *  PRIVATE  *
     *************/
	private:
	
	std::ifstream	_inFile;
	std::ofstream	_outFile;
	std::string		_inFileName;
	std::string		_outFileName;
	std::string		_s1;
	std::string		_s2;
	
	/************
     *  PUBLIC  *
     ************/
	public:
	
	FileEditor(const std::string &inFileName, const std::string &s1, const std::string &s2);
	~FileEditor(void);
	
	int		openFile(void);
	int		editFile(void);
	void	replaceLine(const std::string& line, size_t start);
};

#endif
