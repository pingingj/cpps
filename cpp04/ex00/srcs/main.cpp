/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:59:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/09 15:30:05 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongAnimal.hpp"
#include "../incs/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();	
	const Animal test = *j;
	test.makeSound();
	std::cout << "-----------------------------------------------------" << std::endl;
	delete meta;
	delete j;
	delete i;
	return 0;
}