/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:19:16 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/24 18:25:40 by seokjyoo         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "get_next_line.h"

char	*re_allocate(char *buffer, char *line)
{
	char	*temp;
	char	*return_val;
	char	*enter_loc;
	char	temp_char;

	enter_loc = ft_strchr(buffer, (int) '\n');
	if (enter_loc)
	{
		temp_char = *(enter_loc + 1);
		*(enter_loc + 1) = 0;
	}
	if (line)
	{
		temp = ft_strdup(line);
		return_val = ft_strjoin(temp, buffer);
		free(line);
		free(temp);
	}
	else
		return_val = ft_strdup(buffer);
	if (enter_loc)
		*(enter_loc + 1) = temp_char;
	return (return_val);
}

void	backup_maker(char *buffer, char **backup)
{
	char	*enter_loc;
	size_t	index;

	index = 0;
	enter_loc = ft_strchr(buffer, (int) '\n') + 1;
	while (*buffer)
		buffer++;
	while (enter_loc < buffer)
	{
		(*backup)[index] = *enter_loc;
		index++;
		enter_loc++;
	}
	(*backup)[index] = 0;
}

char	*backup_enter(char *backup)
{
	char	*return_val;
	char	*enter_loc;
	char	temp_char;
	size_t	index;

	index = 0;
	enter_loc = ft_strchr(backup, (int) '\n');
	temp_char = *(enter_loc + 1);
	*(enter_loc + 1) = 0;
	return_val = ft_strdup(backup);
	*(enter_loc + 1) = temp_char;
	while (index < BUFFER_SIZE + 1)
	{
		if (!*(enter_loc + index + 1))
			break ;
		backup[index] = *(enter_loc + index + 1);
		index++;
	}
	backup[index] = 0;
	return (return_val);
}

char	*alloc_line(int fd, char *backup, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_size;
	size_t	index;

	index = 0;
	buffer[BUFFER_SIZE] = 0;
	while (index++ < BUFFER_SIZE)
		buffer[index] = 0;
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		if (ft_strchr(buffer, (int) '\n'))
		{
			line = re_allocate(buffer, line);
			backup_maker(buffer, &backup);
			return (line);
		}
		else
			line = re_allocate(buffer, line);
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = 0;
	}
	if (!read_size)
		backup[0] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	backup[BUFFER_SIZE + 1];

	if (fd < 0)
		return (0);
	line = 0;
	if (!backup[0])
	{
		line = alloc_line(fd, backup, line);
		return (line);
	}
	else
	{
		if (ft_strchr(backup, (int) '\n'))
			return (line = backup_enter(backup));
		else
		{
			line = ft_strdup(backup);
			line = alloc_line(fd, backup, line);
			return (line);
		}
	}
	return (line);
}
