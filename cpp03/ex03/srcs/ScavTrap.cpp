/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:52:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/07 02:37:56 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Steve")
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap (name)
{
	std::cout <<  "ScavTrap Constructor with parameters called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hp = obj.hp;
		this->ep = obj.ep;
		this->atk = obj.atk;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->hp <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is too dead to guard any gates" << std::endl;
		return ;
	}
	if (this->ep <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is taking a nap on the gates" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is now in guard gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hp == 0)
	{
		std::cout << "ScavTrap " << this->name << " can't attack... they are dead." << std::endl;
		return ;
	}
	if (this->ep == 0)
	{
		std::cout << "ScavTrap " << this->name << " can't attack with 0 energy points." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks ";
	std::cout << target << ", causing " << this->atk << " points of damage!" << std::endl;
	this->ep--;
}