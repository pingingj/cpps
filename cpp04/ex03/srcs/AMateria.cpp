/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:46:41 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/03 17:56:02 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &obj)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = obj;
}

AMateria &AMateria::operator=(AMateria const &obj)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if(this != &obj)
	{
		this->type = obj.type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}