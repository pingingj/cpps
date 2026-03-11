/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:15:01 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/03 17:47:09 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const &obj): AMateria(obj)
{
	std::cout << "Cure Copy constructor called" << std::endl;
	*this = obj;
}

Cure	&Cure::operator=(Cure const &obj)
{
	std::cout << "Cure Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	Cure *materia = new Cure(*this);
	return (materia);
}

void	Cure::use(ICharacter &target)
{
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}