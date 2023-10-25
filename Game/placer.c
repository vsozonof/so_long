/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:52:34 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/24 02:02:47 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_wall(t_game_handler *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->wall,
		(ptr->x_pos * 32), (ptr->y_pos * 32));
}

void	place_item(t_game_handler *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->item,
		(ptr->x_pos * 32), (ptr->y_pos * 32));
}

void	place_floor(t_game_handler *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->floor,
		(ptr->x_pos * 32), (ptr->y_pos * 32));
}

void	place_player(t_game_handler *ptr)
{
	ptr->x_player = ptr->x_pos;
	ptr->y_player = ptr->y_pos;
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->player,
		(ptr->x_player * 32), (ptr->y_player * 32));
}

void	place_exit(t_game_handler *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->exit,
		(ptr->x_pos * 32), (ptr->y_pos * 32));
}
