/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 01:02:48 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/07 02:31:57 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Caleb_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->name = "Daniel";
	this->hp = 100;
	this->ep = 50;
	this->atk = 30;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Constructor with parameters called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->atk = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = obj;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap Copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hp = obj.hp;
		this->ep = obj.ep;
		this->atk = obj.atk;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->name;
	std::cout << " and their ClapTrap's name " << this->ClapTrap::name << std::endl;
}