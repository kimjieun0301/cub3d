/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardinal_colors2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:07:23 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/06/02 13:38:57 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	val_rgb_2(char *rgb)
{
	int	index;

	index = 0;
	while (rgb[index])
	{
		if (!(rgb[index] >= '0' && rgb[index] <= '9'))
		{
			if (!(rgb[index] == ','))
				return (-1);
		}
		if (rgb[index] == ',')
		{
			if (index + 1 < 0 || index - 1 < 0)
				return (-1);
			if (!(rgb[index + 1] >= '0' && rgb[index + 1] <= '9'))
				return (-1);
			if (!(rgb[index - 1] >= '0' && rgb[index - 1] <= '9'))
				return (-1);
			if (rgb[index + 1] == '0')
				if (!(rgb[index + 2] == ',' || rgb[index + 2] == '\0'))
					return (-1);
		}
		index++;
	}
	return (0);
}

int	val_rgb(char *rgb)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (rgb[index])
	{
		if (rgb[index] == ',')
			count ++;
			index++;
	}
	if (count != 2)
		return (-1);
	if (rgb[0] == '0')
		if (rgb[1] != ',')
			return (-1);
	if (val_rgb_2(rgb) == -1)
		return (-1);
	return (0);
}

void	token_maker(char **tokens)
{
	if (tokens[1] && tokens[1][ft_strlen(tokens[1]) - 1] != '\n')
	{
		printf("Error\n");
		exit(1);
	}
	if (tokens[1])
		tokens[1][ft_strlen(tokens[1]) - 1] = 0;
}
