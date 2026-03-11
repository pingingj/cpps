/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:03:28 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/03 17:47:14 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
	this->type = "ice";
}


Ice::Ice(Ice const &obj): AMateria(obj)
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = obj;
}

Ice	&Ice::operator=(Ice const &obj)
{
	std::cout << "Ice Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	Ice *materia = new Ice(*this);
	return (materia);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}