/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:48:23 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 02:42:11 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_game_handler	*ptr;

	if (argc != 2)
		return (pr_error("Not enough arguments."));
	else if (!(is_it_a_ber_file(argv)))
		return (pr_error("Incorrect file format (.ber is expected)."));
	ptr = malloc(sizeof(t_game_handler));
	if (!ptr)
		return (pr_error("Allocation error."));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (pr_error("Impossible to read the file."));
	if (!is_the_map_valid(fd, ptr))
		return (free(ptr), 0);
	game_manager(ptr);
	mlx_loop(ptr->mlx);
	free(ptr);
	return (0);
}
