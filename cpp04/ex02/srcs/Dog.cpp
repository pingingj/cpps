/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:52:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/15 17:33:13 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	this->brainz = new Brain;
}

Dog::Dog(const Dog &obj): AAnimal(obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type = obj.type;
	if (obj.brainz != NULL)
		this->brainz = new Brain(*obj.brainz);
	else
		this->brainz = NULL;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->brainz;
		if (obj.brainz != NULL)
			this->brainz =  new Brain(*obj.brainz);
		else
			this->brainz = NULL;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	if (this->brainz)
		delete this->brainz;
}

void	Dog::makeSound() const
{
	std::cout << "The " << this->type << " says woof woof" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brainz);
}

void	Dog::addIdea(std::string idea)
{
	this->brainz->setIdeas(idea);
}

std::string	Dog::seeIdea(unsigned int id) const
{
	return (this->brainz->getIdeas(id));
}