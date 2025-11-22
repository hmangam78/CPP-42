/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:45:02 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/29 11:53:42 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = -1;
	std::cout << std::endl;
	std::cout << GREEN;
	std::cout << "Empty crappy phonebook ready" << std::endl << std::endl;	
	std::cout << RESET;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << std::endl;
	std::cout << RED;
	std::cout << "Phonebook burnt, say goodbye to your contacts!" << std::endl;
	std::cout << RESET;
}

void	PhoneBook::add_contact(void)
{
	std::string	str;
	int			position;

	_index++;
	if (_index > 7)
	{
		std::cout << "Your contact " << _contacts[_index % 8].get_nickname();
		std::cout << " will be replaced" << std::endl;
	}
	position = _index % 8;
	display_line();
	std::cout << "Enter the new contact's first name: ";
	str = validate_entry();
	_contacts[position].set_first_name(str);
	std::cout << "Enter the last name: ";
	str = validate_entry();
	_contacts[position].set_last_name(str);
	std::cout << "Enter their nickname: ";
	str = validate_entry();
	_contacts[position].set_nickname(str);
	std::cout << "Enter the phone number: ";
	str = validate_entry();
	_contacts[position].set_phone(str);
	std::cout << "Enter their darkest secret: ";
	str = validate_entry();
	_contacts[position].set_secret(str);
	display_line();
}

void	PhoneBook::print(Contact contact) const
{
	std::cout << MAGENTA "-----------------------------------" RESET << std::endl;
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
	std::cout << MAGENTA "-----------------------------------" RESET << std::endl;
}

Contact	PhoneBook::get_contact(int index) const
{
	return (this->_contacts[index]);
}

void	PhoneBook::search(void) const
{
	int			i;
	std::string	input;
	int			index;
	int			registers;

	i = 0;
	if (_index == -1)
	{
		std::cout << "The phonebook is empty, add some contacts first";
		std::cout << std::endl;
		return ;
	}
	if (_index >= 8)
		registers = 7;
	else
		registers = _index;
	std::cout << std::setw(35) << std::right << "My awesome crappy phonebook" << std::endl;
	display_line();
	std::cout << "----------|----------|----------|----------" << std::endl;
	std::cout << "-----Index|First name|-Last name|--Nickname" << std::endl;
	while (i <= registers)
	{
		print_short(i);
		i++;
	}
	std::cout << "-------------------------------------------" << std::endl;
	display_line();
	std::cout << std::endl << "Enter the contact's index to be displayed: ";
	std::getline(std::cin, input);
	index = get_int(input);
	if ((index >= 0 && index <= 7) && (index <= this->_index))
		this->print(this->_contacts[index]);
	else
		std::cout << RED "Incorrect option, enter a valid index" RESET << std::endl;
	display_line();
}

void	PhoneBook::print_short(int i) const
{
	std::cout << "---------" << i << "|";
	std::cout << std::setw(10) << std::right;
	if (this->_contacts[i].get_first_name().length() > 10)
		std::cout << this->_contacts[i].get_first_name().substr(0, 9) + ".";
	else
		std::cout << this->_contacts[i].get_first_name();
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	if (this->_contacts[i].get_last_name().length() > 10)
		std::cout << this->_contacts[i].get_last_name().substr(0, 9) + ".";
	else
		std::cout << this->_contacts[i].get_last_name();
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	if (this->_contacts[i].get_nickname().length() > 10)
		std::cout << this->_contacts[i].get_nickname().substr(0, 9) + ".";
	else
		std::cout << this->_contacts[i].get_nickname();
	std::cout << std::endl;
}
