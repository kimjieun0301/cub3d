/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_data_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:05:21 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/25 14:03:13 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	find_same_line_dup(char *str)
{
	int	index;
	int	nsew;

	index = 0;
	nsew = 0;
	while (str[index])
	{
		if (str[index] == 'N' || str[index] == 'S' || str[index] == 'E'
			|| str[index] == 'W')
			nsew++;
		if (nsew > 1)
			return (1);
		index++;
	}
	return (0);
}

int	found_not_accurate_char(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != '0' && str[index] != '1' && str[index] != 'N'
			&& str[index] != 'S' && str[index] != 'E' && str[index] != 'W'
			&& str[index] != ' ' && str[index] != '\n' && str[index] != '\0')
			return (0);
		index++;
	}
	if (find_same_line_dup(str))
		return (0);
	return (1);
}

int	validate_allowed_characters(t_data *data)
{
	t_list	*temp;
	int		trg;

	temp = data->tmp;
	trg = 0;
	while (temp)
	{
		if ((ft_strchr(temp->content, 'N') || ft_strchr(temp->content, 'S')
				|| ft_strchr(temp->content, 'E') || ft_strchr(temp
					->content, 'W')) && trg == 1)
			return (1);
		if (found_not_accurate_char(temp->content))
		{
			if ((ft_strchr(temp->content, 'N') || ft_strchr(temp->content, 'S')
					|| ft_strchr(temp->content, 'E') || ft_strchr(temp
						->content, 'W')) && trg == 0)
					trg = 1;
			temp = temp->next;
		}
		else
			return (1);
	}
	if (trg == 0)
		return (1);
	return (0);
}

int	validate_map_data(t_data *data)
{
	int		trg;

	trg = validate_allowed_characters(data);
	if (trg == 1)
		return (1);
	trg = validate_boundary_line(data);
	return (trg);
}
