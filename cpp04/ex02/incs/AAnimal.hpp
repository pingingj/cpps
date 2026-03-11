/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:32:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/15 17:31:43 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &obj);
		AAnimal &operator=(const AAnimal &obj);
		virtual ~AAnimal();
		std::string	getType() const;
		virtual void	makeSound() const = 0;
};

#endif