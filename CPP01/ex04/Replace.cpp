/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:37:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/08 16:43:31 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

FileEditor::FileEditor(void) {}

int	FileEditor::openFile(void)
{
	inFile.open(fileName.c_str());
	if (!inFile.is_open())
	{
		return (std::cout << fileName << ": " << strerror(errno) << std::endl, 1);
	}
	if (fileName.empty())
	{
		return (std::cout << fileName << ": is empty" << std::endl, 1);
	}
	outFile.open("replacedFile");
	if (!outFile.is_open())
	{
		std::cout << "replacedFile: " << strerror(errno) << std::endl;
		inFile.close();
		return (1);
	}
	return (0);
}

int	FileEditor::replaceLines(void)
{
	std::string line;
	size_t		occStart = 0;
	size_t		occEnd = 0;
	
	while (std::getline(inFile, line))
	{
		occStart = line.find(s1);
		if (occStart != std::string::npos)
		{		
			while (occStart != std::string::npos)
			{
				occEnd = occStart + s2.length();
				outFile.write(line.substr(0, occStart).c_str(), occStart);
				outFile << s2;
				occStart = line.find(s1, occStart + 1);
			}
		}
		if (occStart == std::string::npos)
		{
			outFile.write(line.substr(0, occStart).c_str(), occStart);
		}
	}
	inFile.close();
	outFile.close();
	return (0);
}

FileEditor::~FileEditor(void) {}
