/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:40:38 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/15 20:33:15 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;

//type is gonna be ice or cure
//clone returns a new instance of the same type
//use will display message depending which type of materia it has
class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &obj);
		AMateria &operator=(AMateria const &obj);
		virtual ~AMateria();
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;
};

#endif