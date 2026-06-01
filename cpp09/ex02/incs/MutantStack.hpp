/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:09:10 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/28 14:02:42 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T,Container>
{
	private:

	public:
		MutantStack();
		MutantStack(const MutantStack &obj);
		MutantStack &operator=(const MutantStack &obj);
		~MutantStack();

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		iterator begin();
		iterator end()
		{
			return (this->c.end());
		}
		const_iterator cbegin() const
		{
			return (this->c.begin());
		}
		const_iterator cend() const
		{
			return (this->c.end());
		}
};

#include "MutantStack.tpp"

#endif