/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_parsing_struct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:31:29 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 02:33:39 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_parser	*init_map_parser(void)
{
	int				i;
	t_map_parser	*ptr;

	i = 0;
	ptr = malloc(sizeof(t_map_parser));
	if (!ptr)
		return (NULL);
	ptr->dx = malloc(sizeof(int) * 4);
	ptr->dy = malloc(sizeof(int) * 4);
	if (!ptr->dy || !ptr->dx)
		return (NULL);
	while (i < 4)
	{
		ptr->dx[i] = 0;
		ptr->dy[i] = 0;
		i++;
	}
	ptr->dx[2] = -1;
	ptr->dx[3] = 1;
	ptr->dy[0] = -1;
	ptr->dy[1] = 1;
	ptr->n_x = 0;
	ptr->n_y = 0;
	ptr->n_item = 0;
	return (ptr);
}
