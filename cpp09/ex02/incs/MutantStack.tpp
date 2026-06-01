/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:09:50 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/28 14:03:24 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
	std::cout << "MutantStack default constructor" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "MutantStack default detructor" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &obj) : std::stack<T, Container>(obj)
{

}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &obj)
{
	if (this != &obj)
	{
		this->c = obj.c;
	}
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}