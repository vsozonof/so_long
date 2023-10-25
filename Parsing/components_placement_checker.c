/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_placement_checker.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:05:50 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/21 21:52:02 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	components_checker(char *map, t_map_parser *ptr)
{
	int	spawn;
	int	exit;
	int	i;

	i = 0;
	spawn = 0;
	exit = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			spawn++;
		else if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			ptr->n_item++;
		i++;
	}
	if (spawn != 1 || exit != 1 || ptr->n_item < 1)
		return (pr_error("There is an error with the map components."));
	return (1);
}
