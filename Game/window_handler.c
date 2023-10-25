/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:30:08 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 02:11:59 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_handler(t_game_handler *ptr)
{
	ptr->window = mlx_new_window(ptr->mlx, ptr->x, ptr->y, "so_long");
	if (!(ptr->window))
		return (free(ptr->mlx));
	map_handler(ptr);
}

void	map_handler(t_game_handler *ptr)
{
	ptr->y_pos = 0;
	ptr->x_pos = 0;
	while (ptr->y_pos < (ptr->y / 32))
	{
		if (ptr->map[ptr->y_pos][ptr->x_pos] == '1')
			place_wall(ptr);
		else if (ptr->map[ptr->y_pos][ptr->x_pos] == '0')
			place_floor(ptr);
		else if (ptr->map[ptr->y_pos][ptr->x_pos] == 'C')
			place_item(ptr);
		else if (ptr->map[ptr->y_pos][ptr->x_pos] == 'P')
			place_player(ptr);
		else if (ptr->map[ptr->y_pos][ptr->x_pos] == 'E')
			place_exit(ptr);
		if (ptr->x_pos < (ptr->x / 32))
			ptr->x_pos++;
		else
		{
			ptr->y_pos++;
			ptr->x_pos = 0;
		}
	}
}

void	collect_item(t_game_handler *ptr)
{
	ptr->n_item--;
	ptr->map[ptr->y_player][ptr->x_player] = '0';
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->player,
		(ptr->x_player * 32), (ptr->y_player * 32));
}

void	update_player_pos(t_game_handler *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->player,
		(ptr->x_player * 32), (ptr->y_player * 32));
	ptr->n_move++;
	ft_printf("Number of moves: %i\n", ptr->n_move);
}
