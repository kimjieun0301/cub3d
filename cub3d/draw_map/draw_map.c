/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:20:34 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/26 17:21:13 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	draw_loop(t_main *main)
{
	int		x;
	t_dda	*dda;

	x = 0;
	main->img.img = mlx_new_image(main->mlx.mlx, WIDTH, HEIGHT);
	main->img.addr = mlx_get_data_addr(main->img.img, &main
			->img.bits_per_pixel, &main->img.line_length, &main->img.endian);
	mlx_clear_window(main->mlx.mlx, main->mlx.win);
	while (x < WIDTH)
	{
		dda = (t_dda *)malloc(sizeof(t_dda));
		dda->while_x = x;
		run_dda(main, dda);
		find_fish_tex_dis(main, dda);
		put_pxl_one_line(main, dda);
		x++;
		free(dda);
	}
	mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->img.img, 0, 0);
	return (0);
}

void	set_main_player_2(t_main *main, t_data *data)
{
	main->tex->north->data = (int *)mlx_get_data_addr(main->tex->north->img,
			&(main->tex->north->bpp), &(main->tex->north->line_size),
			&(main->tex->north->endian));
	main->tex->south->img = mlx_xpm_file_to_image(main->mlx.mlx,
			data->south_texture, &(main->tex->south->width),
			&main->tex->south->height);
	main->tex->south->data = (int *)mlx_get_data_addr(main->tex->south->img,
			&(main->tex->south->bpp), &(main->tex->south->line_size),
			&(main->tex->south->endian));
	main->tex->west->img = mlx_xpm_file_to_image(main->mlx.mlx, data
			->west_texture, &(main->tex->west->width),
			&main->tex->west->height);
	main->tex->west->data = (int *)mlx_get_data_addr(main->tex->west->img,
			&(main->tex->west->bpp), &(main->tex->west->line_size),
			&(main->tex->west->endian));
	main->tex->curr = NULL;
	set_player(main->player, data);
}

void	set_main_player(t_main *main, t_data *data)
{
	main->mlx.mlx = mlx_init();
	main->mlx.win = mlx_new_window(main->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	main->data = data;
	main->player = (t_player *)malloc(sizeof(t_player));
	main->tex = ft_calloc(1, sizeof(t_tex));
	main->tex->north = ft_calloc(1, sizeof(t_tex_img));
	main->tex->south = ft_calloc(1, sizeof(t_tex_img));
	main->tex->west = ft_calloc(1, sizeof(t_tex_img));
	main->tex->east = ft_calloc(1, sizeof(t_tex_img));
	main->tex->east->img = mlx_xpm_file_to_image(main->mlx.mlx, data
			->east_texture, &(main->tex->east->width),
			&main->tex->east->height);
	main->tex->east->data = (int *)mlx_get_data_addr(main->tex->east->img,
			&(main->tex->east->bpp), &(main->tex->east->line_size),
			&(main->tex->east->endian));
	main->tex->north->img = mlx_xpm_file_to_image(main->mlx.mlx, data
			->north_texture, &(main->tex->north->width),
			&main->tex->north->height);
	set_main_player_2(main, data);
}

void	draw_map(t_data *data)
{
	t_main	*main;

	main = (t_main *)malloc(sizeof(t_main));
	set_main_player(main, data);
	mlx_hook(main->mlx.win, KEY_PRESS, 0, key_hook, main);
	mlx_hook(main->mlx.win, KEY_CODE_EXIT, 17, window_close, main);
	draw_loop(main);
	mlx_loop(main->mlx.mlx);
}
