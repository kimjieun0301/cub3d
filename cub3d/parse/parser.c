/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:18:23 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/26 16:42:06 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	is_in_valid(char *target)
{
	if (ft_strcmp(target, "NO") == 0)
		return (1);
	else if (ft_strcmp(target, "SO") == 0)
		return (1);
	else if (ft_strcmp(target, "WE") == 0)
		return (1);
	else if (ft_strcmp(target, "EA") == 0)
		return (1);
	else if (ft_strcmp(target, "F") == 0)
		return (1);
	else if (ft_strcmp(target, "C") == 0)
		return (1);
	else
		return (0);
}

int	find_arr(char *temp, char *use_avail)
{
	int	index;

	index = 0;
	if (is_in_valid(temp))
	{
		while (use_avail[index])
		{
			if (temp[1] && use_avail[index + 1] && use_avail[index]
				== temp[0] && use_avail[index + 1] == temp[1])
				return (1);
			else if (use_avail[index] == temp[0] && ft_strlen(temp) == 1)
				return (1);
			index++;
		}
	}
	return (0);
}

char	*set_avail(char *use_avail)
{
	use_avail = ft_calloc(11, 1);
	use_avail[0] = 'N';
	use_avail[1] = 'O';
	use_avail[2] = 'S';
	use_avail[3] = 'O';
	use_avail[4] = 'W';
	use_avail[5] = 'E';
	use_avail[6] = 'E';
	use_avail[7] = 'A';
	use_avail[8] = 'F';
	use_avail[9] = 'C';
	return (use_avail);
}

void	name_validator(char *path)
{
	int		len;

	len = ft_strlen(path);
	if (len < 5)
	{
		printf("error\n");
		exit(1);
	}
	if (path[len - 1] != 'b' || path[len - 2] != 'u'
		|| path[len - 3] != 'c' || path[len - 4] != '.')
	{
		printf("error\n");
		exit(1);
	}
}

int	parse_data(t_data *data, char *path)
{
	char	*line;
	char	*use_avail;
	int		fd;
	int		trg;

	trg = 0;
	use_avail = NULL;
	name_validator(path);
	use_avail = set_avail(use_avail);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (1)
	{
		trg = parse_cardi_col(line, use_avail, data, trg);
		if (trg == 1)
			return (1);
		else if (trg == 2)
			return (parse_map(data, line, fd));
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
