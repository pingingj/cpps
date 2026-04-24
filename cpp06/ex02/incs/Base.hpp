/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:03:24 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/24 18:43:18 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

class A: public Base
{
	
};

class B: public Base
{

};

class C: public Base
{

};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
#endif