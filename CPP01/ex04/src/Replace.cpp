/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:37:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/01 18:10:04 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

FileEditor::FileEditor(const std::string &inFileName, const std::string &s1,
	const std::string &s2) : _inFileName(inFileName), _s1(s1), _s2(s2) {}

void FileEditor::replaceLine(const std::string &line, size_t start)
{
	size_t	end;

	_outFile.write(line.substr(0, start).c_str(), start);
	while (start != std::string::npos)
	{
		end = start + _s1.length();
		_outFile << _s2;
		start = line.find(_s1, end);
		if (start != std::string::npos)
			_outFile.write(line.substr(end, start - end).c_str(), start - end);
	}
	if (end < line.length())
	{
		_outFile.write(line.substr(end).c_str(), line.length() - end);
	}
	_outFile << std::endl;
}

int FileEditor::openFile(void)
{
	_inFile.open(_inFileName.c_str());
	if (!_inFile.is_open())
	{
		std::cerr << _inFileName << ": " << strerror(errno) << std::endl;
		return (1);
	}
	_outFileName = _inFileName + (".replace");
	_outFile.open(_outFileName.c_str());
	if (!_outFile.is_open())
	{
		std::cerr << _outFileName << ": " << strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}

int FileEditor::editFile(void)
{
	size_t	start;

	std::string line;
	if (_s1.empty())
		return (0);
	if (openFile())
		return (1);
	while (std::getline(_inFile, line))
	{
		start = line.find(_s1);
		if (start != std::string::npos)
			replaceLine(line, start);
		else
			_outFile << line << std::endl;
	}
	return (0);
}

FileEditor::~FileEditor(void)
{
	if (_inFile.is_open())
		_inFile.close();
	if (_outFile.is_open())
		_outFile.close();
}
