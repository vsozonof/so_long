# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 08:53:01 by vsozonof          #+#    #+#              #
#    Updated: 2023/10/24 20:26:57 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes
INCLUDES = -I/usr/include -Imlx
RM = rm -f
MLX_DIR = ./mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

COLOUR_GREEN =\033[0;32m
COLOUR_END =\033[0m

SRCS = main.c \
	   Parsing/is_the_map_valid.c \
	   Parsing/is_it_a_ber_file.c \
	   Parsing/wall_placement_checker.c \
	   Parsing/components_placement_checker.c \
	   Parsing/valid_path_finder.c \
	   Parsing/initialize_parsing_struct.c \
	   Parsing/map_path_finder.c \
	   Game/game_manager.c \
	   Game/window_handler.c \
	   Game/init_vars.c \
	   Game/placer.c \
	   Game/quit_game.c \
	   Game/is_move_valid.c \


SRCS_LIBFT 	= lib/libft.a \


all: init $(MLX_LIB) $(NAME)

init:
		@echo "$(COLOUR_GREEN)****** STARTING COMPILATION ******$(COLOUR_END)"
		make all -C ./lib

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(SRCS)
	@echo "$(COLOUR_GREEN)******    CREATING BINARY    ******$(COLOUR_END)"
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_LIBFT) -o $(NAME) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
		@echo "$(COLOUR_GREEN)****** INITIATING CLEAN  ******$(COLOUR_END)"
		make clean -C ./lib
		@echo "$(COLOUR_GREEN)******   CLEAN COMPLETE  ******$(COLOUR_END)"

fclean: 
		@echo "$(COLOUR_GREEN)****** INITIATING FCLEAN ******$(COLOUR_END)"
		make fclean -C ./lib
		$(RM) $(NAME)
		@echo "$(COLOUR_GREEN)******  FCLEAN COMPLETE  ******$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean init re