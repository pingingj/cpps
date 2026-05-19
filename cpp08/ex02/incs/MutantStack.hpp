/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:09:10 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/19 17:57:54 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>

template <typename T>
class MutantStack : std::stack<T>
{
	private:
		std::list<T> stack;
	public:
		MutantStack();
		MutantStack(const MutantStack &obj);
		MutantStack &operator=(const MutantStack &obj);
		~MutantStack();
		void push(T val);
		void pop();
		size_t size();
		typename std::list<T>::iterator top();
		std::list<T>::iterator start();
		std::list<T>::iterator end();
		
};

#endif