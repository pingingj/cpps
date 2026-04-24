/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:08:01 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/24 18:48:01 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
	int randnum;
	Base *base;

	randnum = rand() % 3;
	if (randnum == 0)
	{
		std::cout << "Generated A" << std::endl;
		base = new A;
		return (base);
	}
	else if (randnum == 1)
	{
		std::cout << "Generated B" << std::endl;
		base = new B;
		return (base);
	}
	std::cout << "Generated C" << std::endl;
	base = new C;
	return (base);
}

void	identify(Base *p)
{
	std::cout << "Identify via pointer" << std::endl;
	char identity;
	if (dynamic_cast<A*>(p))
	{
		identity = 'A';
	}
	else if (dynamic_cast<B*>(p))
	{
		identity = 'B';
	}
	else if (dynamic_cast<C*>(p))
	{
		identity = 'C';
	}
	else
	{
		std::cout << "Doesn't correspond to anything!" << std::endl;
		return ;
	}
	std::cout << "identified " << identity << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Identifty via reference" << std::endl;
	Base	test;
	char	identity;
	try
	{
		test = dynamic_cast<A&>(p);
		identity = 'A';
	}
	catch(const std::exception& e)
	{
		try
		{
			test = dynamic_cast<B&>(p);
			identity = 'B';
		}
		catch(const std::exception& e)
		{
			try
			{
				test = dynamic_cast<C&>(p);
				identity = 'C';
			}
			catch(const std::exception& e)
			{
				std::cout << "Doesn't correspond to anything!" << std::endl;
				return ;
			}
		}
	}
	std::cout << "Identified " << identity << std::endl;
}
