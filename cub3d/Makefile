# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 15:08:04 by seokjyoo          #+#    #+#              #
#    Updated: 2023/06/02 13:31:44 by seokjyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLXDIR = ./mlx/
MLXLIB = -L$(MLXDIR) -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
MLX = $(MLXDIR)libmlx.a

LFTDIR = ./LIBFT/
LFTLIB = -L$(LFTDIR) -lft
LIBFT = $(LFTDIR)libft.a

SRC =	./main.c \
		./parse/parser.c \
		./parse/parse_cardinal_colors.c \
		./parse/parse_cardinal_colors1.c \
		./parse/parse_cardinal_colors2.c \
		./parse/GNL/get_next_line.c \
		./parse/parse_map/parse_map.c \
		./parse/parse_map/set_temporary_map.c \
		./parse/parse_map/validate_map_data_char.c \
		./parse/parse_map/validate_map_data_map.c \
		./draw_map/draw_map.c \
		./draw_map/draw_map1.c \
		./draw_map/draw_map2.c \
		./draw_map/mlx_tools.c \
		./draw_map/key_hook.c \
		./draw_map/key_hook1.c \

all : $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) | $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(OBJ) $(LFTLIB) $(MLXLIB) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LFTDIR) bonus

$(MLX):
	@$(MAKE) -C $(MLXDIR)

clean:
		$(RM) $(OBJ)
		@$(MAKE) -C $(LFTDIR) clean
fclean:	clean
		$(RM) $(NAME)
		@$(MAKE) -C $(LFTDIR) fclean
re :	fclean
		$(MAKE) all

.PHONY: all clean fclean re
