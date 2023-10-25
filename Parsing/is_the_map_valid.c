/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_the_map_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:01:19 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 15:40:36 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_the_map_valid(int fd, t_game_handler *p)
{
	char			*map;
	t_map_parser	*ptr;

	map = map_to_str(fd);
	if (!map)
		return (free(map), pr_error("The file is probably empty."));
	if (!charset_checker(map))
		return (free(map), 0);
	p->map = ft_split(map, '\n');
	ptr = init_map_parser();
	if (!wall_checker(map))
		return (free(map), free(ptr->dx), free(ptr->dy), free(ptr),
			ft_split_free(p->map), 0);
	else if (!components_checker(map, ptr))
		return (free(map), free(ptr->dx), free(ptr->dy), free(ptr),
			ft_split_free(p->map), 0);
	else if (!valid_path_finder(map, ptr))
		return (free(map), free(ptr->dx), free(ptr->dy), free(ptr),
			ft_split_free(p->map), 0);
	free(map);
	free(ptr->dx);
	free(ptr->dy);
	free(ptr);
	return (1);
}

int	charset_checker(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!is_in_charset(map[i]))
			return (pr_error("An invalid character was detected."));
		i++;
	}
	return (1);
}

int	is_in_charset(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' || c == '\n')
		return (1);
	else
		return (0);
}

char	*map_to_str(int fd)
{
	char	*map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		map = strjoin_and_free(map, line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	if (!map)
		return (NULL);
	return (map);
}

char	*strjoin_and_free(char *s1, char *s2)
{
	char	*new_map;

	new_map = ft_strjoin(s1, s2);
	if (!new_map)
		return (NULL);
	free(s1);
	free(s2);
	return (new_map);
}
