/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:37:14 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/23 10:36:45 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/amateriatest.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

void	subject_main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	add_to_dropped(AMateria** dropped, AMateria* newitem)
{
	if (!newitem)
		return ;
	for (int i = 0; i < 100; i++)
	{
		if (dropped[i] == NULL)
		{
			dropped[i] = newitem;
			return ;
		}
	}
}

void	dropItem(AMateria **dropped, ICharacter* character, int idx)
{
	AMateria* tmp;

	tmp = character->handOutMateria(idx);
	add_to_dropped(dropped, tmp);
	character->unequip(idx);
}

void	printline(void)
{
	std::cout << std::endl;
	std::cout << "<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << std::endl;
}

void	run_tests(void)
{
	printline();
	ICharacter*	bob = new Character("bob");
	ICharacter*	me = new Character("me");
	AMateria*	dropped[100];
	for (int i = 0; i < 100; i++)
		dropped[i] = NULL;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	printline();
	std::cout << " # Cloning test, should be unique instances #" << std::endl;
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("ice");
	std::cout << "Address of tmp1 -> " << tmp1 << std::endl;
	std::cout << "Address of tmp2 -> " << tmp2 << std::endl;
	delete tmp1;
	delete tmp2;

	printline();
	std::cout << " # Equip/Use/Unequip lifecicle #" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << " ~ Last materia created not assigned, main program keeps it ~"
			  << std::endl;
	delete tmp;

	printline();
	std::cout << " # Deep copy in copy constructor #" << std::endl;
	ICharacter*	characterA = new Character("a");
	tmp = src->createMateria("ice");
	characterA->equip(tmp);
	ICharacter* characterB = new Character(*(dynamic_cast <Character*>(characterA)));
	std::cout << " ~ Address if the first ice owned by A -> "
			  << characterA->handOutMateria(0) << std::endl;
	std::cout << " ~ Address if the second ice owned by B -> "
			  << characterB->handOutMateria(0) << std::endl << std::endl;
	std::cout << "<<<Deleting first character>>> " << std::endl;
	delete characterA;
	std::cout << std::endl << "<<<Deleting second character>>>" << std::endl;
	delete characterB;

	printline();
	std::cout << " # Dropping an item and trying to use it later #" << std::endl;
	dropItem(dropped, bob, 0);
	bob->use(0, *me);

	printline();
	std::cout << " # Learning the same materia again, is new materia? #" << std::endl;
	src->learnMateria(new Ice());
	for (int i = 0; i < 4; i++)
		std::cout << "Materia at index " << i << " " << src->getMateria(i) << std::endl;

	printline();
	std::cout << " # Non existent materia creation #" << std::endl;
	tmp = src->createMateria("Lightning bolt");
	std::cout << " ~ Materia created -> " << tmp << std::endl;

	printline();
	int	pos = -1;
	std::cout << " # Accesing wrong index #" << std::endl;
	std::cout << "<<< Trying to use item at position " << pos << ">>>" << std::endl;
	bob->use(pos, *me);
	std::cout << " # Accesing empty slot #" << std::endl;
	pos = 3;
	std::cout << "<<< Trying to use item at position " << pos << ">>>" << std::endl;
	bob->use(pos, *me);

	printline();
	for (int i = 0; i < 100; i++)
		delete dropped[i];
	delete src;
	delete me;
	delete bob;
}
