/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:48:23 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/18 15:20:46 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (pr_error("Not enough arguments."));
	else if (!(is_it_a_ber_file(argv)))
		return (pr_error("Incorrect format (.ber is expected)."));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (pr_error("Impossible to read the file."));
	if (!is_the_map_valid(fd))
		return (0);
	
	// void	*mlx_ptr;
	// void	*win_ptr;

	// mlx_ptr = mlx_init();
	// if (!mlx_ptr)
	// 	return (1);
	// win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "RIP Maelle");
	// if (!win_ptr)
	// 	return (free(mlx_ptr), 1);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
	return (0);
}
