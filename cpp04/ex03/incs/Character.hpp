/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:30:19 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/03 17:59:48 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

#define MAX_FLOOR 10

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria *inv[4];
		AMateria *floor[MAX_FLOOR];
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &obj);
		Character &operator=(Character const &obj);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif