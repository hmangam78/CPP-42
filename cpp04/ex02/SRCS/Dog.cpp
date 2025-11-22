/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:42:56 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/07 11:23:01 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void)
{
	std::cout << "Woof woof!" << std::endl;
}

std::string Dog::getType(void)
{
	return(this->type);
}

std::string Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));	
}

void	Dog::setIdea(const std::string& idea, int i)
{
	this->_brain->setIdea(idea, i);
}