/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:13:11 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/06/02 12:32:58 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "struct.h"
# include "../mlx/mlx.h"
# include "../LIBFT/libft.h"
# include "../parse/GNL/get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080
# define KEY_PRESS 2
# define KEY_CODE_EXIT 17

// parse_part
int		parse_data(t_data *data, char *path);
int		validate_map_data(t_data *data);
int		validate_boundary_line(t_data *data);
int		parse_map(t_data *data, char *line, int fd);
int		parse_cardi_col(char *line, char *use_avail, t_data *data, int trg);
char	**temporary_map(t_data *data);
int		validate_text_info(t_data *data);
void	free_tokens(char **tokens);
void	del_use_avail(char *use_avail, char *tokens);
int		convert_rgb_to_int(char *rgb);
int		find_arr(char *temp, char *use_avail);
int		val_rgb(char *rgb);
void	token_maker(char **tokens);
// parse_part end

// draw_part
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		convert_rgb_to_int(char *rgb);
void	draw_map(t_data *data);
int		draw_loop(t_main *main);
int		key_hook(int keycode, t_main *main);
int		window_close(t_main *main);
void	set_player_dir_detail(t_player *player,
			int flag, double num1, double num2);
void	set_player_dir(t_player *player, t_data *data);
void	set_player(t_player *player, t_data *data);
void	set_side_dist(t_main *main, int *step_x, int *step_y, t_dda *dda);
void	set_variables(t_main *main, int *step_x, int *step_y, t_dda *dda);
void	run_dda(t_main *main, t_dda *dda);
void	find_fish_tex_dis(t_main *main, t_dda *dda);
void	check_see_another_block(t_main *main, t_dda *dda);
void	put_pxl_one_line(t_main *main, t_dda *dda);
void	move_forward(t_main *main);
void	move_backward(t_main *main);
void	see_right(t_main *main);
// draw_part end

#endif