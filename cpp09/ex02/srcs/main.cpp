/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/28 13:59:58 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "Main as mutantstack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top of the stack: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		const MutantStack<int> copied(mstack);
		MutantStack<int>::const_iterator c_it = copied.cbegin();
		MutantStack<int>::const_iterator c_ite = copied.cend();
		std::cout << "Const iterators" << std::endl;
		while (c_it != c_ite)
		{
			std::cout << *c_it << std::endl;
			++c_it;
		}
	}
	{
		std::cout << "Main as list" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top of the stack: " << mstack.front() << std::endl;
		mstack.pop_front();
		std::cout << "stack size: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		const std::list<int> copied(mstack);
		std::list<int>::const_iterator c_it = copied.begin();
		std::list<int>::const_iterator c_ite = copied.end();
		std::cout << "Const iterators" << std::endl;
		while (c_it != c_ite)
		{
			std::cout << *c_it << std::endl;
			++c_it;
		}
		// return 0;	
	}
	{
		MutantStack<int, std::list<int> > test;
		MutantStack<int, std::list<int> >::iterator it;
		MutantStack<int, std::list<int> >::iterator ite;
		test.push(100);
		test.push(50);
		it = test.begin();
		ite = test.end();
		test.pop();
		while(it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
}