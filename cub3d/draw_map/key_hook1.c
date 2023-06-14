/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:35:52 by jkim3             #+#    #+#             */
/*   Updated: 2023/05/26 18:26:26 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	move_forward(t_main *main)
{
	if (main->data->map[(int)main->player->loca_y][(int)(main->player->loca_x
		+ main->player->dir_x * 0.11)]
			&& main->data->map[(int)main->player->loca_y][(int)(main->
			player->loca_x + main->player->dir_x * 0.11)] != '1')
		main->player->loca_x += main->player->dir_x * 0.1;
	if (main->data->map[(int)(main->player->loca_y + main->player->dir_y
			* 0.11)][(int)main->player->loca_x]
			&& main->data->map[(int)(main->player->loca_y + main->player->dir_y
			* 0.11)][(int)main->player->loca_x] != '1')
		main->player->loca_y += main->player->dir_y * 0.1;
}

void	move_backward(t_main *main)
{
	if (main->data->map[(int)main->player->loca_y][(int)(main->player->loca_x
		- main->player->dir_x * 0.11)]
			&& main->data->map[(int)main->player->loca_y][(int)(main->player->
			loca_x - main->player->dir_x * 0.11)] != '1')
		main->player->loca_x -= main->player->dir_x * 0.1;
	if (main->data->map[(int)(main->player->loca_y - main->player->dir_y
			* 0.11)][(int)main->player->loca_x]
			&& main->data->map[(int)(main->player->loca_y - main->player->
			dir_y * 0.11)][(int)main->player->loca_x] != '1')
		main->player->loca_y -= main->player->dir_y * 0.1;
}

void	see_right(t_main *main)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = main->player->dir_x;
	old_plane_x = main->player->plane_x;
	main->player->dir_x = main->player->dir_x
		* cos(-0.1) - main->player->dir_y * sin(-0.1);
	main->player->dir_y = old_dir_x * sin(-0.1)
		+ main->player->dir_y * cos(-0.1);
	main->player->plane_x = main->player->plane_x
		* cos(-0.1) - main->player->plane_y * sin(-0.1);
	main->player->plane_y = old_plane_x * sin(-0.1)
		+ main->player->plane_y * cos(-0.1);
}
