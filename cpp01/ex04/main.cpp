/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:28:51 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/27 11:33:17 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int	arg_check(int args, char **argv)
{
	if (args != 4)
	{
		std::cout << "Wrong arguments. Usage: 'Sedisforlosers <filename>";
		std::cout << " <str_to_sub> <sub_str>'" << std::endl;
		return (1);
	}
	std::ifstream	inputfile(argv[1]);
	if (!inputfile)
	{
		std::cout << "Invalid input file" << std::endl;
		return (1);
	}
	std::string	to_find = argv[2];
	std::string replace = argv[3];
	if ((to_find.length() == 0) || (replace.length() == 0))
	{
		std::cout << "The strings to search and replace musn't be empty" << std::endl;
		return (1);
	}
	inputfile.close();
	return (0);
}

void	search_n_replace(char **argv)
{
	size_t			pos;
	std::ifstream	inputfile(argv[1]);
	std::string		to_find = argv[2];
	std::string		replace = argv[3];
	std::string		line = "";
	std::string		filename = std::string(argv[1]) + ".replace";
	std::ofstream	output(filename.c_str());
	if (!output)
	{
		std::cout << "Error creating output file" << std::endl;
		exit(1);
	}
	while (std::getline(inputfile, line))
	{
		while ((pos = line.find(to_find)) != std::string::npos)
		{
			line.erase(pos, to_find.length());
			line.insert(pos, replace);
			pos += replace.length();
		}
		output << line << std::endl;
	}
	inputfile.close();
	output.close();
}

int	main(int args, char** argv)
{
	if (arg_check(args, argv))
		return (1);
	search_n_replace(argv);
	return (0);
}