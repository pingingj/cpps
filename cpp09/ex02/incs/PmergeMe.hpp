/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:48:46 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/24 22:09:17 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <limits>
#include <cstdlib>

template <typename container>
void	print_container(container &cont)
{
	typename container::iterator it;
	it = cont.begin();
	while(it != cont.end())
	{
		// std::cout << " (" << it->first << ", " << it->second << ") ";
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

class PmergeMe
{
	private:		
		//vars
		std::vector<int> _vec;
		std::deque<int>	_deq;
		int				_straggler;
		bool			_hasStraggler;
		
		template <typename c_pair>
		c_pair init_container()
		{
			c_pair cont;
			int	x;
			int y;
			for(size_t i = 0; i + 1 < this->_vec.size(); i += 2)
			{
				x = this->_vec[i];
				y = this->_vec[i + 1];
				if (x > y)
					std::swap(x, y);
				cont.push_back(std::make_pair(x, y));
			}
			if (this->_vec.size() % 2 != 0)
			{
				_hasStraggler = true;
				_straggler = this->_vec.back();
			}
			return cont;
		}

		template <typename container>
		container
	
	public:
		//constructors
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

		//funcs
		bool	parse(char *argv);
		void	sort_vector();
		void	sort_deque();
};

#endif