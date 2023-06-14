/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:03:16 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/26 18:05:43 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	see_left(t_main *main)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = main->player->dir_x;
	old_plane_x = main->player->plane_x;
	main->player->dir_x = main->player->dir_x
		* cos(0.1) - main->player->dir_y * sin(0.1);
	main->player->dir_y = old_dir_x * sin(0.1)
		+ main->player->dir_y * cos(0.1);
	main->player->plane_x = main->player->plane_x
		* cos(0.1) - main->player->plane_y * sin(0.1);
	main->player->plane_y = old_plane_x * sin(0.1)
		+ main->player->plane_y * cos(0.1);
}

void	move_left(t_main *main)
{
	double	new_dir_x;
	double	new_dir_y;

	new_dir_x = main->player->dir_y;
	new_dir_y = -main->player->dir_x;
	if (main->data->map[(int)main->player->loca_y][(int)(main->player->loca_x
		+ new_dir_x * 0.11)]
			&& main->data->map[(int)main->player->loca_y][(int)(main->
			player->loca_x + new_dir_x * 0.11)] != '1')
		main->player->loca_x += new_dir_x * 0.1;
	if (main->data->map[(int)(main->player->loca_y + new_dir_y * 0.11
		)][(int)main->player->loca_x]
			&& main->data->map[(int)(main->player->loca_y + new_dir_y * 0.11
			)][(int)main->player->loca_x] != '1')
		main->player->loca_y += new_dir_y * 0.1;
}

void	move_right(t_main *main)
{
	double	new_dir_x;
	double	new_dir_y;

	new_dir_x = main->player->dir_y;
	new_dir_y = -main->player->dir_x;
	if (main->data->map[(int)main->player->loca_y][(int)(main->player->loca_x
		+ (new_dir_x * -0.11))]
			&& main->data->map[(int)main->player->loca_y][(int)(main->
			player->loca_x + (new_dir_x * -0.11))] != '1')
		main->player->loca_x += new_dir_x * -0.1;
	if (main->data->map[(int)(main->player->loca_y + new_dir_y * -0.11
		)][(int)main->player->loca_x]
			&& main->data->map[(int)(main->player->loca_y + new_dir_y * -0.11
			)][(int)main->player->loca_x] != '1')
		main->player->loca_y += new_dir_y * -0.1;
}

int	key_hook(int keycode, t_main *main)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		move_forward(main);
	else if (keycode == 1)
		move_backward(main);
	else if (keycode == 2)
		move_right(main);
	else if (keycode == 0)
		move_left(main);
	else if (keycode == 123)
		see_right(main);
	else if (keycode == 124)
		see_left(main);
	draw_loop(main);
	return (0);
}

int	window_close(t_main *main)
{
	free(main);
	exit(0);
	return (0);
}
