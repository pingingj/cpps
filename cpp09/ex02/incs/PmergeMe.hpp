/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:48:46 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/29 19:32:25 by dgarcez-         ###   ########.fr       */
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

template <typename Container>
void	print_container_pair(Container &cont)
{
	typename Container::iterator it;
	it = cont.begin();
	while(it != cont.end())
	{
		std::cout << " (" << it->first << ", " << it->second << ") ";
		// std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template <typename Container>
void	print_container(Container &cont)
{
	typename Container::iterator it;
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
		

		void	ford_vector(int recurs_lvl);
		void	ford_deque(int recurs_lvl);
		std::vector<int> jacobsthal(size_t n);
		void	use_jacobsthal(std::vector<std::pair<int, int> > &vect_pair,int &n_per_pair, std::vector<int> &main_chain, std::vector<int> &pend);
		std::vector	<int>init_chains(std::vector<std::pair<int, int> > &vect_pair, int &n_per_pair, std::vector<int> &pend);


		template <typename c_pair, typename Container>
		c_pair init_container(Container &cont, int &n_per_pair)
		{
			c_pair cont_pair;
			for(size_t i = n_per_pair - 1; i + n_per_pair < cont.size(); i += n_per_pair * 2)
			{
				if (cont.at(i) > cont.at(i + n_per_pair))
					std::swap_ranges(cont.begin() + i - (n_per_pair - 1), cont.begin() + i + 1, cont.begin() + i + 1);
				cont_pair.push_back(std::make_pair(cont.at(i), cont.at(i + n_per_pair)));
			}
			return cont_pair;
		}


	
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