/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:59:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/09 16:04:24 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include <iomanip>

int main()
{
	// std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
	// int amount = 6;

	// Animal *animals[amount];
	// for(int i = 0; i < amount / 2; i++)
	// 	animals[i] = new Dog();
	// for(int i = amount / 2; i < amount; i++)
	// 	animals[i] = new Cat();
	Dog dog;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "idea from " << dog.getType() << ": " << dog.seeIdea(3) << std::endl;
	dog.addIdea("potato");
	std::cout << "idea from " << dog.getType() << ": " << dog.seeIdea(3) << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	Dog	bat(dog);
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "this dog brain is " << dog.getBrain() << std::endl;
	std::cout << "this bat brain is " << bat.getBrain() << std::endl;
	std::cout << "idea from dog: " << dog.seeIdea(3) << std::endl;
	std::cout << "idea from bat: " << bat.seeIdea(3) << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	Cat cat;
	Cat test;
	test.addIdea("cucumber");
	cat = test;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "this cat brain is " << cat.getBrain() << std::endl;
	std::cout << "this test brain is " << test.getBrain() << std::endl;
	std::cout << "idea from cat: " << cat.seeIdea(3) << std::endl;
	std::cout << "idea from test: " << test.seeIdea(3) << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	// for(int i = 0; i < amount; i++)
	// 	delete animals[i];
	return 0;
}