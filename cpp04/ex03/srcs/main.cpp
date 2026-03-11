/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:02:18 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/09 16:26:02 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ICharacter.hpp"
#include "../incs/Character.hpp"
#include "../incs/MateriaSource.hpp"
#include "../incs/Ice.hpp"
#include "../incs/Cure.hpp"
#include <iomanip>

int main()
{
	{
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// ICharacter* me = new Character("me");
		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// ICharacter* bob = new Character("bob");
		// me->use(0, *bob);
		// me->use(1, *bob);
		// delete bob;
		// delete me;
		// delete src;
		// return 0;
	}
	{
		std::cout << "-----------------------------------------------------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		AMateria* cure_mat = new Cure();
		AMateria* test_mat = new Ice();
		AMateria* ice_test = new Ice();
		AMateria* cured = new Cure();
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		std::cout << "-----------------------------------------------------" << std::endl;
		src->learnMateria(cure_mat);
		src->learnMateria(test_mat);
		src->learnMateria(ice_test);
		src->learnMateria(cured);
		tmp = src->createMateria("ice");
		std::cout << "-----------------------------------------------------" << std::endl;
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp); 
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->unequip(1);
		me->use(3, *bob);
		me->use(3, *me);
		me->unequip(1);
		std::cout << "-----------------------------------------------------" << std::endl;
		delete bob;
		delete me;
		delete src;
		return 0;
	}
	{
		// ICharacter *test = new Character("bob");
		// IMateriaSource *src = new MateriaSource();
		// AMateria	*tmp;

		// src->learnMateria(new Ice());
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// tmp = src->createMateria("ice");
		// test->equip(tmp);
		// test->unequip(0);
		// delete test;
		// delete src;
	}
}