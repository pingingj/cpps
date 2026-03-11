/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/07 02:59:39 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

int main()
{
	ScavTrap	scavs("Andre");
	ClapTrap	claps("Pedro");
	FragTrap	frags("Brew");
	DiamondTrap	diamonds("Dan");
	claps.attack("wall");
	claps.attack("wall");
	scavs.beRepaired(50);
	scavs.attack("Pedro");
	frags.highFivesGuys();
	frags.takeDamage(30);
	claps.attack("wall");
	claps.attack("wall");
	scavs.takeDamage(50);
	claps.attack("wall");
	claps.attack("wall");
	claps.takeDamage(9);
	diamonds.whoAmI();
	claps.beRepaired(4);
	ClapTrap	traps(claps);
	traps.beRepaired(8);
	claps.attack("wall");
	claps.takeDamage(1);
	claps.attack("wall");
	claps.attack("wall");
	claps.beRepaired(10);
	claps.takeDamage(1);
	claps.takeDamage(1000);
	claps.attack("wall");
	claps.attack("wall");
	claps.attack("wall");
	scavs.guardGate();
	scavs.takeDamage(5050);
	scavs.guardGate();
	frags.takeDamage(800);
	frags.takeDamage(300);
	frags.highFivesGuys();
	diamonds.attack("wall");
	diamonds.guardGate();
	diamonds.takeDamage(99);
	diamonds.guardGate();
	diamonds.attack("poopie");
	diamonds.highFivesGuys();
	diamonds.beRepaired(100);
}