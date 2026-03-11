/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/06 21:31:52 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

int main()
{
	ScavTrap	huge("Damn");
	ClapTrap	claps("Pedro");
	claps.attack("wall");
	claps.attack("wall");
	huge.beRepaired(50);
	huge.attack("Pedro");
	claps.attack("wall");
	claps.attack("wall");
	huge.takeDamage(50);
	claps.attack("wall");
	claps.attack("wall");
	claps.takeDamage(9);
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
	huge.guardGate();
	huge.takeDamage(5050);
}