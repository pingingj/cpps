/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:48:53 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/09 14:36:16 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &obj)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete(this->materias[i]);
			if (obj.materias[i])
				this->materias[i] = obj.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete(this->materias[i]);
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "Can't learn non existant materia" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
		{
			std::cout << "Learned " << m->getType() << std::endl;
			this->materias[i] = m;
			return ;
		}
	}
	std::cout << "Unlearned " << this->materias[0]->getType();
	std::cout << " and learned " << m->getType() << std::endl;
	delete this->materias[0];
	this->materias[0] = m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL && this->materias[i]->getType() == type)
		{
			return (this->materias[i]->clone());
		}
	}
	std::cout << type << " can't be created, not learned" << std::endl;
	return (NULL);
}