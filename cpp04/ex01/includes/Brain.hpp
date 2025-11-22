/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 07:45:48 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/07 11:17:33 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class	Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		Brain(std::string ideaset[100]);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain(void);
		std::string getIdea(const int i) const;
		void        setIdea(const std::string& idea, int i);
};

#endif