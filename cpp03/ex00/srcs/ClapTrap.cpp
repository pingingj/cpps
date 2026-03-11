/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:03:56 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/07 00:32:08 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->name = "Caleb";
	this->hp = 10;
	this->ep = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout <<  "Constructor with parameters called" << std::endl;
	this->name = name;
	this->hp = 10;
	this->ep = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hp = obj.hp;
		this->ep = obj.ep;
		this->atk = obj.atk;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack... they are dead." << std::endl;
		return ;
	}
	if (this->ep == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack with 0 energy points." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks ";
	std::cout << target << ", causing " << this->atk << " points of damage!" << std::endl;
	this->ep--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	if (amount >= this->hp)
		amount = this->hp;
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " takes ";
	std::cout << amount << " damage they are now at " << this->hp << std::endl;
	if (this->hp <= 0)
		std::cout << "ClapTrap " << this->name << " has died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't heal... they are dead." << std::endl;
		return ;
	}
	if (this->ep == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't repair with 0 energy points." << std::endl;
		return ;
	}
	this->hp += amount;
	std::cout << "ClapTrap " << this->name << " heals ";
	std::cout << amount << " hp they are now at " << this->hp << std::endl;
	this->ep--;
}