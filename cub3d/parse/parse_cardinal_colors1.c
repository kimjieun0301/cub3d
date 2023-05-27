/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardinal_colors1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:40:20 by jkim3             #+#    #+#             */
/*   Updated: 2023/05/26 16:43:11 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	convert_rgb_to_int(char *rgb)
{
	int		r;
	int		g;
	int		b;
	int		color;

	while (*rgb == 'C' || *rgb == 'F' || *rgb == ' ')
		rgb++;
	r = ft_atoi(rgb);
	while (*rgb != ',')
		rgb++;
	g = ft_atoi(++rgb);
	while (*rgb != ',')
		rgb++;
	b = ft_atoi(++rgb);
	color = r * 256 * 256 + g * 256 + b;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (color);
}

void	del_use_avail2(char *use_avail, int index)
{
	int	zero_count;

	zero_count = 0;
	while (use_avail[index])
	{
		if (use_avail[index] == '0')
		{
			while (use_avail[index + zero_count] == '0')
				zero_count++;
			break ;
		}
		index++;
	}
	while (use_avail[index] && use_avail[index + zero_count])
	{
		use_avail[index] = use_avail[index + zero_count];
		index++;
	}
	use_avail[ft_strlen(use_avail) - zero_count] = '\0';
}

void	del_use_avail(char *use_avail, char *tokens)
{
	int	index;

	index = 0;
	while (use_avail[index])
	{
		if (use_avail[index] == tokens[0])
		{
			if (use_avail[index + 1] && ft_strlen(tokens) == 2
				&& tokens[1] == use_avail[index + 1])
			{
				use_avail[index] = '0';
				use_avail[index + 1] = '0';
				break ;
			}
			else if (ft_strlen(tokens) == 1)
			{
				use_avail[index] = '0';
				break ;
			}
		}
		index++;
	}
	index = 0;
	del_use_avail2(use_avail, index);
}

void	free_tokens(char **tokens)
{
	int	index;

	index = 0;
	while (tokens[index])
	{
		free(tokens[index]);
		index++;
	}
	free(tokens);
}

int	validate_text_info(t_data *data)
{
	int	fd;

	fd = open(data->north_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(data->south_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(data->west_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(data->east_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}
