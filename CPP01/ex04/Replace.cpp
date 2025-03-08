/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:37:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 18:15:52 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

FileEditor::FileEditor(void) {}

void	FileEditor::replaceLine(const std::string& line, size_t start)
{
	size_t	end;

	outFile.write(line.substr(0, start).c_str(), start);
	while (start != std::string::npos)
	{
		end = start + s1.length();
		outFile << s2;
		start = line.find(s1, end);
		if (start != std::string::npos)
			outFile.write(line.substr(end, start - end).c_str(), start - end);	
	}
	if (end < line.length())
	{
		outFile.write(line.substr(end).c_str(), line.length() - end);
	}
	outFile << std::endl;
}

int	FileEditor::openFile(void)
{
	inFile.open(inFileName.c_str());
	if (!inFile.is_open())
	{
		std::cout << inFileName << ": " << strerror(errno) << std::endl;
		return (1);
	}
	outFileName = inFileName + (".replace");
	outFile.open(outFileName.c_str());
	if (!outFile.is_open())
	{
		std::cout << outFileName << ": " << strerror(errno) << std::endl;
		inFile.close();
		return (1);
	}
	return (0);
}

int	FileEditor::editFile(void)
{
	std::string line;
	size_t		start;
	
	if (openFile())
		return (1);
	while (std::getline(inFile, line))
	{
		start = line.find(s1);
		if (start != std::string::npos)
			replaceLine(line, start);
		else
			outFile << line << std::endl;
	}
	inFile.close();
	outFile.close();
	return (0);
}

FileEditor::~FileEditor(void) {}
