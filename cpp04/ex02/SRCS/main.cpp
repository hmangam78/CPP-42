/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:31:55 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/23 10:13:30 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void	printline(void)
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int	main(void)
{
	Animal*	pets[5];
	int		i;

	i = 0;
	pets[0] = new Dog();
	pets[1] = new Cat();
	pets[2] = new Dog();
	pets[3] = new Cat();
	printline();
	while (i < 4)
	{
		(*pets[i]).makeSound();
		i++;
	}
	printline();
	(*pets[0]).setIdea("Eat that sausage", 0);
	(*pets[1]).setIdea("Find a warm, cozy corner", 0);
	(*pets[2]).setIdea("Steal that sock! Run!", 0);
	(*pets[3]).setIdea("Jump over your human's laptop while he's working", 0);

	i = 0;
	while (i < 4)
	{
		std::cout << "Pet " << i << " which is a " << (pets[i]->getType())
		          << " has this idea: " << (pets[i]->getIdea(0)) << std::endl;
		i++;
	}
	printline();
	std::cout << "Cloning Dog<<<<<<<<<<<<<<<<<" << std::endl;
	pets[4] = new Dog(dynamic_cast<Dog&>(*pets[0]));
	std::cout << "Pet 4 is a " << pets[4]->getType() << " and has this idea: "
	          << pets[4]->getIdea(0) << std::endl;
	pets[0]->setIdea("Let's poo on the carpet!", 0);
	std::cout << "Pet 0 has a new idea: " << pets[0]->getIdea(0) << std::endl;
	std::cout << "But Pet 4 has this one: " << pets[4]->getIdea(0) << std::endl;
	printline();
	i = 0;
	while (i < 5)
	{
		delete (pets[i]);
		i++;
	}
	printline();
	/*
	std::cout << "Testing instantiation of a basic Animal" << std::endl;
	pets[5] = new Animal(); // Compilation warning, not allowed.
	pets[5]->makeSound();
	delete pets[5];
	*/
	return (0);
}