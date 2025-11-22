/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:26:11 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/29 11:53:33 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search(void) const;
		void	print(Contact contact) const;
		Contact	get_contact(int index) const;
		void	print_short(int i) const;
};

#endif