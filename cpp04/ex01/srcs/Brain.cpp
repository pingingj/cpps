/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:45:38 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/07 20:22:19 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "ice cream";
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = obj;
}

Brain	&Brain::operator=(const Brain &obj)
{
	std::cout << "Brain assignment copy operator called" << std::endl;
	if(this != &obj)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeas(unsigned int id)
{
	if (id <= 99)
		return (this->ideas[id]);
	return ("empty brain (invalid number of ideas 0-99)");
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}