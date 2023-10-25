/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:48:24 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/22 16:20:21 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_spwn_itm_path(char **map, int y, int x, t_map_parser	*ptr)
{
	int	i;

	i = -1;
	if (map[y][x] == 'C')
	{
		map[y][x] = '0';
		ptr->ret_x = x;
		ptr->ret_y = y;
		ptr->n_item--;
		return (1);
	}
	else if (ptr->n_item == 0 && map[y][x] == 'E')
		return (1);
	if (map[y][x] != 'E')
		map[y][x] = '2';
	while (++i < 4)
	{
		ptr->n_x = x + ptr->dx[i];
		ptr->n_y = y + ptr->dy[i];
		if (map[ptr->n_y][ptr->n_x] == 'C' || map[ptr->n_y][ptr->n_x] == '0'
			|| map[ptr->n_y][ptr->n_x] == 'E')
			if (find_spwn_itm_path(map, ptr->n_y, ptr->n_x, ptr))
				return (1);
	}
	return (0);
}
