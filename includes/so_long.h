/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:48:37 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/18 17:09:57 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

int		parsing_manager(int fd);
int		is_the_map_valid(int fd);
int		is_it_a_ber_file(char **argv);
int		extension_checker(char *set, int len_start, char **argv);
char	*map_to_str(int fd);
char	*strjoin_and_free(char *s1, char *s2);
int		wall_checker(char *map);
int		is_the_map_a_rectangle(char *map);
int		are_placed_walls_valid(char *map, int n_line);
int		first_and_last_checker(char *map, int n_line);
int		middle_line_checker(char *map);
int		components_checker(char *map);


#endif