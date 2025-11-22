/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:01:01 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/23 10:06:03 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	displayline(void)
{
	std::cout << std::endl;
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>"
			  << std::endl << std::endl;
}

int	main(void)
{
	displayline();
	
	Animal* indy = new Dog();
	Animal* casper = new Cat();
	Animal* rat = new Animal();

	indy->makeSound();
	casper->makeSound();
	rat->makeSound();

	delete indy;
	delete casper;
	delete rat;
	
	displayline();
	
	WrongAnimal* wrongcat = new WrongCat();

	wrongcat->makeSound();

	delete wrongcat;

	displayline();
	
	return (0);
}