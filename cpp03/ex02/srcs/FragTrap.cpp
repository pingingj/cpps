/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:26:44 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/07 02:58:38 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Fred")
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor with parameters called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = obj;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		this->hp = obj.hp;
		this->ep = obj.ep;
		this->atk = obj.atk;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hp <= 0)
	{
		std::cout << "FragTrap " << this->name << " can't give out high fives... he's dead lol" << std::endl;
		return ;
	}
	if (this->ep <= 0)
	{
		std::cout << "FragTrap " << this->name << " is too tired for high fives :l" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " says any high fives guys!?" << std::endl;
	this->ep--;
}