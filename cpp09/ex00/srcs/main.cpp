/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/09 15:39:32 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"



int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Invalid amount of arguments! ./bitcoin <input_file>" << std::endl;
		return (1);
	}
	std::map<std::string, float>	db;
	std::ifstream	input_file(argv[1]);
	// std::cout << "------DB-------" << std::endl;
	if (parse(input_file, db) == false)
		return (1);
	// std::cout << "------Input------" << std::endl;
	search_btc(input_file, db);
}