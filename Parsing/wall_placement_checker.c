/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_placement_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:41:34 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/22 22:59:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_checker(char *map)
{
	if (!is_the_map_a_rectangle(map))
		return (pr_error("The map isn't a rectangle."));
	else if (!are_placed_walls_valid(map, is_the_map_a_rectangle(map)))
		return (pr_error("The wall placement is invalid."));
	return (1);
}

int	are_placed_walls_valid(char *map, int n_line)
{
	if (!first_and_last_checker(map, n_line))
		return (0);
	else if (!middle_line_checker(map))
		return (0);
	return (1);
}

int	middle_line_checker(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
			i++;
		if (map[i] == '\n' && map[i - 1] == '1' && (map[i + 1] == '1'))
			i += 2;
		else if (map[i] == '\n' && (map[i - 1] != '1' || (map[i + 1] != '1')))
			return (0);
	}
	return (1);
}

int	first_and_last_checker(char *map, int n_line)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		while (map[i] && (c == 0 || c == n_line - 1) && map[i] != '\n')
		{
			if (map[i] == '1')
				i++;
			else
				return (0);
		}
		while (map[i] && map[i] != '\n')
			i++;
		c++;
		if (map[i] == '\n')
			i++;
	}
	return (1);
}

int	is_the_map_a_rectangle(char *map)
{
	int	len;
	int	lines;
	int	i;

	lines = 0;
	len = 0;
	i = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
		{
			if (lines == 0)
				len++;
			i++;
		}
		lines++;
		if (map[i] == '\n')
			i++;
		else if (((len * lines) + (lines - 1)) != i)
			return (0);
	}
	return (lines);
}
