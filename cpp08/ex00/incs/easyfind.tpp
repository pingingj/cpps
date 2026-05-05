/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:25:23 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/05 18:53:16 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T> int easyfind(T container, int num)
{
	T::iterator i;
	i = std::find(container.begin(), container.end(), num);
	if (i != container.end())
		
}