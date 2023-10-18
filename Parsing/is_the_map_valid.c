/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_the_map_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:01:19 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/18 17:14:38 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_the_map_valid(int fd)
{
	char	*map;

	map = map_to_str(fd);
	if (!wall_checker(map))
		return (free(map), 0);
	else if (!components_checker(map))
		return (free(map), 0);
	free(map);
	return (1);
}

char	*map_to_str(int fd)
{
	char	*map;
	char	*line;
	int		i;

	i = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map = strjoin_and_free(map, line);
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
	free(s1);
	free(s2);
	return (new_map);
}
