/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:48:37 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/25 15:38:00 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_map_parser
{
	int	*dx;
	int	*dy;
	int	n_y;
	int	n_x;
	int	ret_y;
	int	ret_x;
	int	n_item;
}	t_map_parser;

typedef struct s_game_handler
{
	char	**map;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*floor;
	void	*item;
	void	*player;
	void	*exit;
	void	*player_exit;
	int		n_item;
	int		y;
	int		x;
	int		y_pos;
	int		x_pos;
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		n_move;

}	t_game_handler;

// !--------------------------------------------------------------------------
// ?                           MAP PARSING FUNCTIONS
// !--------------------------------------------------------------------------

int				is_the_map_valid(int fd, t_game_handler *p);
int				charset_checker(char *map);
int				is_in_charset(char c);
int				is_it_a_ber_file(char **argv);
int				extension_checker(char *set, int len_start, char **argv);
char			*map_to_str(int fd);
char			*strjoin_and_free(char *s1, char *s2);
int				wall_checker(char *map);
int				is_the_map_a_rectangle(char *map);
int				are_placed_walls_valid(char *map, int n_line);
int				first_and_last_checker(char *map, int n_line);
int				middle_line_checker(char *map);
int				components_checker(char *map, t_map_parser *ptr);
int				valid_path_finder(char *map, t_map_parser *ptr);
int				*get_spawn_position(char **map);
int				find_spwn_itm_path(char **map, int y, int x, t_map_parser *ptr);
t_map_parser	*init_map_parser(void);
void			map_set_to_one(char **map);

// !--------------------------------------------------------------------------
// ?                           GAME FUNCTIONS
// !--------------------------------------------------------------------------

void			game_manager(t_game_handler *ptr);
void			window_handler(t_game_handler *ptr);
void			init_vars(t_game_handler *ptr);
void			get_x_y_len(t_game_handler *ptr);
void			get_n_of_items(t_game_handler *ptr);
void			map_handler(t_game_handler *ptr);
void			place_wall(t_game_handler *ptr);
void			place_item(t_game_handler *ptr);
void			place_floor(t_game_handler *ptr);
void			place_player(t_game_handler *ptr);
void			place_exit(t_game_handler *ptr);
int				movement_manager(int key, t_game_handler *ptr);
void			movement_handler_y(t_game_handler *ptr, char pos, int n);
void			movement_handler_x(t_game_handler *ptr, char pos, int n);
void			update_player_pos(t_game_handler *ptr);
int				is_move_valid_y(t_game_handler *ptr, char pos, int n);
int				is_move_valid_x(t_game_handler *ptr, char pos, int n);
void			collect_item(t_game_handler *ptr);
void			exit_game(t_game_handler *ptr);
int				end_program(t_game_handler *ptr);

#endif