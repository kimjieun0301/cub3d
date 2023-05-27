/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:25:06 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/25 15:15:56 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	validate_last_line(int fd, char *line)
{
	while (line)
	{
		if (!(line[0] == '\0' || line[0] == '\n'))
		{
			if (line[0])
				free(line);
			return (1);
		}
		if (line[0])
			free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	set_line_align_tmp(char *line, int fd, t_data *data, int trg)
{
	t_list	*tmp;

	tmp = NULL;
	line = get_next_line(fd);
	while (line && (line[0] == '\n' || line[0] == '\0'))
	{
		if (line[0])
			free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (!(line[0] == '\n' || line[0] == '\0'))
			ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(line)));
		else
			break ;
		if (line && line[0])
			free(line);
		line = get_next_line(fd);
	}
	if (line && (line[0] == '\n' || line[0] == '\0'))
		trg = validate_last_line(fd, line);
	data->tmp = tmp;
	return (trg);
}

int	parse_map(t_data *data, char *line, int fd)
{
	int		trg;

	trg = set_line_align_tmp(line, fd, data, 0);
	if (trg == 1)
	{
		close(fd);
		return (trg);
	}
	trg = validate_map_data(data);
	close(fd);
	return (trg);
}
