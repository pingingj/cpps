/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:48:46 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/07/02 17:37:35 by dgarcez-         ###   ########.fr       */
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
#include <algorithm>
#include <cmath>

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

template <typename C_pair>
int		find_pair(C_pair &cont_pair, int find)
{
	for(size_t i = 0; i < cont_pair.size(); i++)
	{
		if (find == cont_pair[i].first)
			return cont_pair[i].second;
	}
	return (-1);
}

class PmergeMe
{
	private:		
		//vars
		std::vector<int> _vec;
		std::deque<int>	_deq;
		int				_straggler;
		bool			_hasStraggler;
		int				counter;

		void	ford_vector(int recurs_lvl);
		void	ford_deque(int recurs_lvl);
		// void	use_jacobsthal(std::vector<std::pair<int, int> > &vect_pair,int &n_per_pair, std::vector<int> &main_chain, std::vector<int> &pend);
		// std::vector	<int>init_chains(std::vector<std::pair<int, int> > &vect_pair, int &n_per_pair, std::vector<int> &pend);

		template <typename C_pair, typename Container>
		C_pair init_container(Container &cont, int &n_per_pair)
		{
			C_pair cont_pair;
			for(size_t i = n_per_pair - 1; i + n_per_pair < cont.size(); i += n_per_pair * 2)
			{
				if (cont.at(i) > cont.at(i + n_per_pair))
					std::swap_ranges(cont.begin() + i - (n_per_pair - 1), cont.begin() + i + 1, cont.begin() + i + 1);
				counter++;
				cont_pair.push_back(std::make_pair(cont.at(i), cont.at(i + n_per_pair)));
			}
			return (cont_pair);
		}

		template <typename Container>
		size_t	binarysearch(Container &main_chain, int &to_compare, int &n_per_pair, size_t &right)
		{
			size_t left = 0;
			while (left <= right)
			{
				size_t middle = (left + right) / 2;
				size_t index = middle * n_per_pair + (n_per_pair - 1);
				if(to_compare < main_chain[index])
				{
					if(middle == 0)
					{
						left = 0;
						break;
					}
					right = middle - 1;
				}
				else
				{
					left = middle + 1;
				}
				this->counter++;
			}
			return (left);
		}

		template <typename Container, typename C_pair>
		Container init_chains(C_pair &cont_pair, int &n_per_pair, Container &pend)
		{
			// std::cout << "-----------INITING CHAINS--------" << std::endl;
			Container main_chain;
			for(size_t i = 0; i < cont_pair.size() * 2; i++)
			{
				size_t start = i * n_per_pair;
				size_t end  = start + n_per_pair;
				if(i == 0 || i == 1 || i % 2 != 0)
					main_chain.insert(main_chain.end(),this->_vec.begin() + start, this->_vec.begin() + end);
				else
					pend.insert(pend.end(), this->_vec.begin() + start, this->_vec.begin() + end);
			}
			size_t consumed = cont_pair.size() * 2 * n_per_pair;
			if(consumed + n_per_pair <= _vec.size()) 
				pend.insert(pend.end(), _vec.begin() + consumed, _vec.begin() + consumed + n_per_pair);
			return(main_chain);
		}

		template <typename Container>
		Container jacobsthal(size_t n)
		{
			size_t	num;
			Container seq;
			seq.push_back(3);
			if (n <= 2)
				return (seq);
			seq.push_back(5);
			if (n <= 5)
				return (seq);
			for(int i = 2; i; i++)
			{
				num = seq[i - 1] + 2 * seq[i - 2];
				if (num >= n)
				{
					seq.push_back(num);
					break ;
				}
				seq.push_back(num);
			}
			return (seq);
		}

		template <typename Container, typename C_pair>
		void	use_jacobsthal(C_pair &cont_pair,int &n_per_pair, Container &main_chain, Container &pend)
		{
			// std::cout << "----------------------------STARTING JACOBING----------------------------" << std::endl;
			// print_container_pair(cont_pair);
			size_t	order = 0;
			size_t	prev_order = 1;
			Container seq;

			seq = jacobsthal<Container>(pend.size() / n_per_pair);
			int pair_count = pend.size() / n_per_pair + 1;

			for(size_t i = 0; i < seq.size(); i++)
			{
				order = std::min(seq[i], pair_count);
				for(size_t j = order; j > prev_order; j--)
				{
					int	current_pair = j - 2;
					size_t idx = current_pair * n_per_pair + (n_per_pair - 1);
					int		pair;
					pair = find_pair(cont_pair, pend[idx]);
					size_t right;
					size_t left;
					if (pair == -1)
						right = main_chain.size() / n_per_pair - 1;
					else
						right = std::distance(main_chain.begin(),std::find(main_chain.begin(),main_chain.end(), pair)) / n_per_pair;
					left = binarysearch(main_chain, pend[idx], n_per_pair, right);
					main_chain.insert(main_chain.begin() + left * n_per_pair, pend.begin() + idx - n_per_pair + 1, pend.begin() + idx + 1);
				}
				prev_order = order;
			}
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