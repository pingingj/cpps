/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:35:37 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/09 15:06:51 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"
#include "../incs/AMateria.hpp"

Character::Character()
{
	std::cout << "Character Default constructor called" << std::endl;
	this->name = "NPC";
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
	for (int i = 0; i < MAX_FLOOR; i++)
		this->floor[i] = NULL;
}

Character::Character(std::string const &name)
{
	std::cout << "Character Constructor with parameters called name = " << name << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
	for (int i = 0; i < MAX_FLOOR; i++)
		this->floor[i] = NULL;
}

Character::Character(Character const &obj)
{
	std::cout << "Character Copy constructor called" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		for(int i = 0; i < 4; i++)
		{
			if (obj.inv[i])
				this->inv[i] = obj.inv[i]->clone();
			else
				this->inv[i] = NULL;
		}
	}
}

Character &Character::operator=(Character const &obj)
{
	
	std::cout << "Character copy assignment operator called" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		for(int i = 0; i < 4; i++)
		{
			if (this->inv[i])
				delete(this->inv[i]);
			if (obj.inv[i])
				this->inv[i] = obj.inv[i]->clone();
			else
				this->inv[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete(this->inv[i]);
		this->inv[i] = NULL;
	}
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		if (this->floor[i])
			delete(this->floor[i]);
	}
}

std::string const &Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "Tried to equip non existant materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if(this->inv[i] == NULL)
		{
			this->inv[i] = m;
			std::cout << this->getName() << " equipped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}


// have to change this cuz i cant delete slot have to save somewhere
void	Character::unequip(int idx)
{
	int	i;

	i = 0;
	if (idx < 0 || idx >= 4 || this->inv[idx] == NULL)
	{
		std::cout << "Invalid index or inventory slot " << idx << " is already empty!" << std::endl; 
		return ;
	}
	std::cout << this->getName() << " Has unequipped " << this->inv[idx]->getType() << std::endl;
	while (i < MAX_FLOOR && this->floor[i] != NULL)
		i++;
	if (i == MAX_FLOOR)
	{
		i = 0;
		delete this->floor[i];
	}
	this->floor[i] = this->inv[idx];
	this->inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || this->inv[idx] == NULL)
	{
		std::cout << "Invalid index or inventory slot " << idx << " is empty!" << std::endl; 
		return ;
	}
	this->inv[idx]->use(target);
}