/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:16:51 by jkim3             #+#    #+#             */
/*   Updated: 2023/06/06 12:28:42 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	set_player_dir_detail(t_player *player, int flag
	, double num1, double num2)
{
	if (flag == 0)
	{
		player->dir_x = 0.01;
		player->dir_y = num1;
		player->plane_x = num2;
		player->plane_y = 0.01;
	}
	if (flag == 1 && num1 > 0)
	{
		player->dir_x = num1;
		player->dir_y = num2;
		player->plane_x = 0.01;
		player->plane_y = 0.66;
	}
	else if (flag == 1 && num1 < 0)
	{
		player->dir_x = num1;
		player->dir_y = num2;
		player->plane_x = 0.01;
		player->plane_y = -0.66;
	}
}

void	set_player_dir(t_player *player, t_data *data)
{
	if (data->map[(int)player->loca_y][(int)player->loca_x] == 'N')
		set_player_dir_detail(player, 0, -1.01, 0.66);
	else if (data->map[(int)player->loca_y][(int)player->loca_x] == 'S')
		set_player_dir_detail(player, 0, 1.01, -0.66);
	else if (data->map[(int)player->loca_y][(int)player->loca_x] == 'E')
		set_player_dir_detail(player, 1, 1.01, 0.01);
	else if (data->map[(int)player->loca_y][(int)player->loca_x] == 'W')
		set_player_dir_detail(player, 1, -1.01, 0.01);
}

void	set_player(t_player *player, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||
				data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				player->loca_x = x + 0.1;
				player->loca_y = y + 0.1;
			}
			x++;
		}
		y++;
	}
	set_player_dir(player, data);
}

void	set_side_dist(t_main *main, int *step_x, int *step_y, t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		*step_x = -1;
		dda->side_dist_x = (main->player->loca_x
				- dda->map_x) * dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1.0
				- main->player->loca_x) * dda->delta_dist_x;
	if (dda->ray_dir_y < 0)
	{
		*step_y = -1;
		dda->side_dist_y = (main->player->loca_y
				- dda->map_y) * dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1.0
				- main->player->loca_y) * dda->delta_dist_y;
}

void	set_variables(t_main *main, int *step_x, int *step_y, t_dda *dda)
{
	double	camera_x;

	camera_x = 2 * dda->while_x / (double)WIDTH - 1;
	dda->ray_dir_x = main->player->dir_x + main->player->plane_x * camera_x;
	dda->ray_dir_y = main->player->dir_y + main->player->plane_y * camera_x;
	if (dda->ray_dir_y == 0)
		dda->delta_dist_x = 0;
	else if (fabs(dda->ray_dir_x) < 1e-10)
		dda->delta_dist_x = 1;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	if (dda->ray_dir_x == 0)
		dda->delta_dist_y = 0;
	else if (fabs(dda->ray_dir_x) < 1e-10)
		dda->delta_dist_y = 1;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	*step_x = 1;
	*step_y = 1;
	set_side_dist(main, step_x, step_y, dda);
}
