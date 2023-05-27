# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 15:08:04 by seokjyoo          #+#    #+#              #
#    Updated: 2023/05/26 16:50:56 by jkim3            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

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
		install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LFTDIR) bonus

$(MLX):
	@$(MAKE) -C $(MLXDIR)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re :	fclean
		$(MAKE) all

.PHONY: all clean fclean re
