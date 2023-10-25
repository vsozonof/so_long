/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_finder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:41:51 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/22 22:29:29 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path_finder(char *map, t_map_parser *ptr)
{
	char			**s_map;
	int				*pos;

	s_map = ft_split(map, '\n');
	pos = get_spawn_position(s_map);
	if (!find_spwn_itm_path(s_map, pos[0], pos[1], ptr))
		return (free(pos), ft_split_free(s_map),
			pr_error("No valid path found."));
	while (ptr->n_item > 0)
	{
		map_set_to_one(s_map);
		if (!find_spwn_itm_path(s_map, ptr->ret_y, ptr->ret_x, ptr))
			return (free(pos), ft_split_free(s_map),
				pr_error("No valid path found."));
	}
	map_set_to_one(s_map);
	if (!find_spwn_itm_path(s_map, ptr->ret_y, ptr->ret_x, ptr))
		return (free(pos), ft_split_free(s_map),
			pr_error("No valid path found."));
	free(pos);
	ft_split_free(s_map);
	return (1);
}

void	map_set_to_one(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '2')
				map[y][x] = '0';
			x++;
		}
		x = 0;
		y++;
	}
}

int	*get_spawn_position(char **map)
{
	int	y;
	int	x;
	int	*tab;

	y = 0;
	x = 0;
	tab = malloc(sizeof(int) * 2);
	while (map[y])
	{
		while (map[y][x] && map[y] && map[y][x] != 'P')
			x++;
		if (map[y][x] == 'P')
			break ;
		y++;
		x = 0;
	}
	if (!tab)
		return (NULL);
	tab[0] = y;
	tab[1] = x;
	return (tab);
}
