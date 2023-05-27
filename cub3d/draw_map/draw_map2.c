/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:16:58 by jkim3             #+#    #+#             */
/*   Updated: 2023/05/26 18:19:37 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	check_see_another_block(t_main *main, t_dda *dda)
{
	if (dda->side == 0)
	{
		if (main->player->loca_x > dda->map_x)
			main->tex->curr = main->tex->west;
		else
			main->tex->curr = main->tex->east;
	}
	else
	{
		if (main->player->loca_y > dda->map_y)
			main->tex->curr = main->tex->north;
		else
			main->tex->curr = main->tex->south;
	}
}

void	find_fish_tex_dis(t_main *main, t_dda *dda)
{
	check_see_another_block(main, dda);
	if (dda->side == 0)
	{
		dda->fish_dis = (dda->map_x - main->player->loca_x
				+ (1 - dda->step_x) / 2) / dda->ray_dir_x;
			main->tex->curr->wall_x = main->player->loca_y
			+ (dda->fish_dis * dda->ray_dir_y);
			main->tex->curr->wall_x -= floor(main->tex->curr->wall_x);
	}
	else
	{
		dda->fish_dis = (dda->map_y - main->player->loca_y
				+ (1 - dda->step_y) / 2) / dda->ray_dir_y;
			main->tex->curr->wall_x = main->player->loca_x
			+ (dda->fish_dis * dda->ray_dir_x);
			main->tex->curr->wall_x -= floor(main->tex->curr->wall_x);
	}
	main->tex->curr->tex_x = (int)(main->tex->curr->wall_x
			* (double)(main->tex->curr->width));
	if (dda->side == 0 && dda->ray_dir_x < 0)
		main->tex->curr->tex_x = main->tex->curr->width
			- main->tex->curr->tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y > 0)
		main->tex->curr->tex_x = main->tex->curr->width
			- main->tex->curr->tex_x - 1;
}

void	run_dda(t_main *main, t_dda *dda)
{
	int	hit;

	hit = 0;
	dda->map_x = main->player->loca_x;
	dda->map_y = main->player->loca_y;
	while (hit == 0)
	{
		set_variables(main, &dda->step_x, &dda->step_y, dda);
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (main->data->map[dda->map_y][dda->map_x] == '1')
			hit = 1;
	}
}

void	draw_pxl_img(t_main *main, int upper_end, int down_end, t_dda *dda)
{
	int		y;
	double	draw_ratio;
	int		tex_y;

	y = -1;
	while (++y < upper_end)
		my_mlx_pixel_put(&main->img, dda->while_x, y, main->data
			->ceiling_color);
	while (y <= down_end)
	{
		draw_ratio = (((y - upper_end) * 1.0) / (down_end - upper_end));
		tex_y = (int)(draw_ratio * (double)(main->tex->curr->height));
		if (down_end == HEIGHT - 1)
		{
			draw_ratio = (HEIGHT * 1.0) / dda->height_x;
			tex_y = (int)(((main->tex->curr->height / 2) * (1 - draw_ratio))
					+ (y * draw_ratio * main->tex->curr->height / HEIGHT));
		}
		my_mlx_pixel_put(&main->img, dda->while_x, y, main->tex->curr->data
		[(tex_y * main->tex->curr->width) + main->tex->curr->tex_x]);
		y++;
	}
	while (y < HEIGHT)
		my_mlx_pixel_put(&main->img, dda->while_x, y++,
			main->data->floor_color);
}

void	put_pxl_one_line(t_main *main, t_dda *dda)
{
	int		height_x;
	int		upper_end;
	int		down_end;

	height_x = (int)(HEIGHT / dda->fish_dis);
	if (height_x < 0)
		height_x = 0;
	upper_end = -height_x / 2 + HEIGHT / 2;
	down_end = height_x / 2 + HEIGHT / 2;
	if (upper_end < 0)
		upper_end = 0;
	if (down_end >= HEIGHT)
		down_end = HEIGHT - 1;
	dda->height_x = height_x;
	draw_pxl_img(main, upper_end, down_end, dda);
}
