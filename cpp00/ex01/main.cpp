/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:56:23 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/25 19:10:05 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	command;

	command = "";
	while (command != "EXIT")
	{
		std::cout << "You can add new contacts with 'ADD', ";
		std::cout << "look for a contact using 'SEARCH', ";
		std::cout << "or quit the program using 'EXIT'." << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			book.add_contact();
		else if (command == "SEARCH")
			book.search();
		else
			std::cout << std::endl;
	}
	return (0);
}