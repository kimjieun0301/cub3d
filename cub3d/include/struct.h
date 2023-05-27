/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:14:14 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/26 16:12:06 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			**map;
	int				floor_color;
	int				ceiling_color;
	struct s_list	*tmp;
}	t_data;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_player {
	double	loca_x;
	double	loca_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_dda {
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	camera_x;
	double	fish_dis;
	int		height_x;
	int		while_x;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
}			t_dda;

typedef struct s_tex_img
{
	void		*img;
	int			*data;
	int			width;
	int			height;
	int			bpp;
	int			line_size;
	int			endian;
	int			tex_x;
	double		wall_x;
}				t_tex_img;

typedef struct s_tex
{
	t_tex_img	*north;
	t_tex_img	*south;
	t_tex_img	*west;
	t_tex_img	*east;
	t_tex_img	*curr;
}				t_tex;

typedef struct s_main
{
	t_mlx		mlx;
	t_player	*player;
	t_data		*data;
	t_img		img;
	t_tex		*tex;
}				t_main;

#endif