/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:37:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 18:45:44 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

FileEditor::FileEditor(const std::string &inFileName, const std::string &s1,
	const std::string &s2) : inFileName(inFileName), s1(s1), s2(s2) {}

void FileEditor::replaceLine(const std::string &line, size_t start)
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

int FileEditor::openFile(void)
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
		return (1);
	}
	return (0);
}

int FileEditor::editFile(void)
{
	size_t	start;

	std::string line;
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
	return (0);
}

FileEditor::~FileEditor(void)
{
	if (inFile.is_open())
		inFile.close();
	if (outFile.is_open())
		outFile.close();
}
