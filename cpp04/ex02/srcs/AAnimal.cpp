/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:33:03 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/15 17:32:03 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default constructor called" << std::endl;
	this->type = "Empty";
}

AAnimal::AAnimal(const std::string &type)
{
	std::cout << "AAnimal Constructor with parameters called" << std::endl;
	this->type = type;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = obj;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "The " << this->type << " says [ERROR]" << std::endl;
}