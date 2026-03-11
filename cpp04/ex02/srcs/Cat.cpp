/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:59:19 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/15 17:33:07 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
	this->brainz = new Brain();
}

Cat::Cat(const Cat &obj): AAnimal(obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type = obj.type;
	if (obj.brainz != NULL)
		this->brainz = new Brain(*obj.brainz);
	else
		this->brainz = NULL;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
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

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brainz;
}

void	Cat::makeSound() const
{
	std::cout << "The " << this->type << " says meow" << std::endl;
}

void	Cat::addIdea(std::string idea)
{
	this->brainz->setIdeas(idea);
}

std::string	Cat::seeIdea(unsigned int id) const
{
	return (this->brainz->getIdeas(id));
}

Brain	*Cat::getBrain() const
{
	return (this->brainz);
}