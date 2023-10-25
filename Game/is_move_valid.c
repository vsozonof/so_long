/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_move_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:07:24 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/24 20:27:19 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_valid_y(t_game_handler *ptr, char pos, int n)
{
	if (pos == 'y' && n == -1)
	{
		if (ptr->map[(ptr->y_player - 1)][ptr->x_player] == '1')
			return (0);
		else
			return (1);
	}
	else if (pos == 'y' && n == 1)
	{
		if (ptr->map[(ptr->y_player + 1)][ptr->x_player] == '1')
			return (0);
		else
			return (1);
	}
	return (0);
}

int	is_move_valid_x(t_game_handler *ptr, char pos, int n)
{
	if (pos == 'x' && n == -1)
	{
		if (ptr->map[ptr->y_player][(ptr->x_player - 1)] == '1')
			return (0);
		else
			return (1);
	}
	else if (pos == 'x' && n == 1)
	{
		if (ptr->map[ptr->y_player][(ptr->x_player + 1)] == '1')
			return (0);
		else
			return (1);
	}
	return (0);
}
