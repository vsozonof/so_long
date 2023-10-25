/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:21:21 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 02:07:40 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_manager(t_game_handler *ptr)
{
	ptr->mlx = mlx_init();
	if (!(ptr->mlx))
		return ;
	init_vars(ptr);
	window_handler(ptr);
	mlx_hook(ptr->window, 17, 0, end_program, ptr);
	mlx_key_hook(ptr->window, movement_manager, ptr);
}

int	movement_manager(int key, t_game_handler *ptr)
{
	if (key == 65307)
		end_program(ptr);
	else if (key == 122)
		movement_handler_y(ptr, 'y', -1);
	else if (key == 113)
		movement_handler_x(ptr, 'x', -1);
	else if (key == 115)
		movement_handler_y(ptr, 'y', 1);
	else if (key == 100)
		movement_handler_x(ptr, 'x', 1);
	return (0);
}

void	movement_handler_y(t_game_handler *ptr, char pos, int n)
{
	if (pos == 'y')
	{
		if (is_move_valid_y(ptr, pos, n) && n == -1)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->floor,
				(ptr->x_player * 32), (ptr->y_player * 32));
			ptr->y_player -= 1;
			update_player_pos(ptr);
		}
		else if (is_move_valid_y(ptr, pos, n) && n == 1)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->floor,
				(ptr->x_player * 32), (ptr->y_player * 32));
			ptr->y_player += 1;
			update_player_pos(ptr);
		}
	}
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->exit,
		(ptr->x_exit * 32), (ptr->y_exit * 32));
	if (ptr->map[ptr->y_player][ptr->x_player] == 'C')
		collect_item(ptr);
	else if (ptr->map[ptr->y_player][ptr->x_player] == 'E')
		exit_game(ptr);
	mlx_do_sync(ptr->mlx);
}

void	movement_handler_x(t_game_handler *ptr, char pos, int n)
{
	if (pos == 'x')
	{
		if (is_move_valid_x(ptr, pos, n) && n == -1)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->floor,
				(ptr->x_player * 32), (ptr->y_player * 32));
			ptr->x_player -= 1;
			update_player_pos(ptr);
		}
		else if (is_move_valid_x(ptr, pos, n) && n == 1)
		{
			mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->floor,
				(ptr->x_player * 32), (ptr->y_player * 32));
			ptr->x_player += 1;
			update_player_pos(ptr);
		}
	}
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->exit,
		(ptr->x_exit * 32), (ptr->y_exit * 32));
	if (ptr->map[ptr->y_player][ptr->x_player] == 'C')
		collect_item(ptr);
	else if (ptr->map[ptr->y_player][ptr->x_player] == 'E')
		exit_game(ptr);
	mlx_do_sync(ptr->mlx);
}
