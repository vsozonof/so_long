/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:33:38 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 02:09:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game_handler *ptr)
{
	int		img_width;
	int		img_height;

	get_x_y_len(ptr);
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx, "./Images/Grass.xpm",
			&img_width, &img_height);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "./Images/Wall.xpm",
			&img_width, &img_height);
	ptr->item = mlx_xpm_file_to_image(ptr->mlx, "./Images/Item.xpm",
			&img_width, &img_height);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./Images/Player.xpm",
			&img_width, &img_height);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "./Images/Exit.xpm",
			&img_width, &img_height);
	ptr->player_exit = mlx_xpm_file_to_image(ptr->mlx, "./Images/Pexit.xpm",
			&img_width, &img_height);
	get_n_of_items(ptr);
	ptr->n_move = 0;
}

void	get_n_of_items(t_game_handler *ptr)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	ptr->n_item = 0;
	while (ptr->map[i])
	{
		while (ptr->map[i][c])
		{
			if (ptr->map[i][c] == 'C')
				ptr->n_item++;
			else if (ptr->map[i][c] == 'E')
			{
				ptr->y_exit = i;
				ptr->x_exit = c;
			}
			c++;
		}
		c = 0;
		i++;
	}
}

void	get_x_y_len(t_game_handler *ptr)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (ptr->map[y])
	{
		while (ptr->map[y][x])
			x++;
		y++;
		ptr->x = (x * 32);
		x = 0;
	}
	ptr->y = (y * 32);
}
