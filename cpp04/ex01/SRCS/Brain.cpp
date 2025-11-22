/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 07:45:58 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/07 11:15:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
    int i;

    i = 0;
    while (i < 100)
    {
        ideas[i] = "";
        i++;
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string ideaset[100])
{
    int i;

    i = 0;
    while (i < 100)
    {
        ideas[i] = ideaset[i];
        i++;
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	int i;
	i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return (*this);
	else
	{
		int i;
		i = 0;
		while (i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
		std::cout << "Brain assignment operator called" << std::endl;
		return (*this);
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(const int i) const
{
	if ((i < 0) || (i > 99))
	{
		std::cout << "This brain only has 100 ideas (0-99)" << std::endl;
		return (std::string());
	}
	else
		return (this->ideas[i]);
}

void        Brain::setIdea(const std::string& idea, int i)
{
	if ((i < 0) || (i > 99))
		std::cout << "Wrong index value, valid range 0 to 99" << std::endl;
	else
		this->ideas[i] = idea;
}