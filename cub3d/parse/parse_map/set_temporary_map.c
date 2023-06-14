/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_temporary_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:24:11 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/04/30 20:45:57 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	find_height(t_data *data, int *height)
{
	t_list	*temp;
	int		index;
	char	*str_temp;

	temp = data->tmp;
	*height = 0;
	while (temp)
	{
		str_temp = temp->content;
		index = 0;
		while (str_temp[index])
			index++;
		*height += 1;
		temp = temp->next;
	}
}

void	free_all(t_data *data)
{
	t_list	*temp;
	t_list	*temp2;

	temp = data->tmp;
	while (temp)
	{
		temp2 = temp->next;
		free(temp->content);
		free(temp);
		temp = temp2;
	}
}

char	**temporary_map(t_data *data)
{
	t_list	*temp;
	char	**map;
	int		height;
	int		index;

	temp = data->tmp;
	find_height(data, &height);
	map = (char **)malloc(sizeof(char *) * (height + 1));
	index = 0;
	while (temp)
	{
		map[index] = ft_strdup(temp->content);
		temp = temp->next;
		index++;
	}
	map[index] = NULL;
	free_all(data);
	return (map);
}
