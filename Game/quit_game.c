/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:25:30 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 02:10:24 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_program(t_game_handler *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->item);
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_destroy_image(ptr->mlx, ptr->floor);
	mlx_destroy_image(ptr->mlx, ptr->wall);
	mlx_destroy_image(ptr->mlx, ptr->exit);
	mlx_destroy_image(ptr->mlx, ptr->player_exit);
	mlx_destroy_window(ptr->mlx, ptr->window);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	ft_split_free(ptr->map);
	free(ptr);
	exit(EXIT_SUCCESS);
}

void	exit_game(t_game_handler *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->window, ptr->player_exit,
		(ptr->x_player * 32), (ptr->y_player * 32));
	if (ptr->n_item == 0)
	{
		ft_printf("Congratulations, you win!");
		end_program(ptr);
	}
	else
		ft_printf("You need to collect all items before leaving!\n");
}
