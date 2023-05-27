/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardinal_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:34:55 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/26 16:41:58 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	token_maker(char **tokens)
{
	int	index;

	index = 0;
	if (tokens[1])
		tokens[1][ft_strlen(tokens[1]) - 1] = 0;
}

void	parse_line(t_data *data, char *line, char *use_avail)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	token_maker(tokens);
	if (ft_strcmp(tokens[0], "NO") == 0)
		data->north_texture = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "SO") == 0)
		data->south_texture = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "WE") == 0)
		data->west_texture = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "EA") == 0)
		data->east_texture = ft_strdup(tokens[1]);
	else if (ft_strcmp(tokens[0], "F") == 0)
		data->floor_color = convert_rgb_to_int(tokens[1]);
	else if (ft_strcmp(tokens[0], "C") == 0)
		data->ceiling_color = convert_rgb_to_int(tokens[1]);
	del_use_avail(use_avail, tokens[0]);
	free_tokens(tokens);
	if (data->ceiling_color == -1 || data->floor_color == -1)
	{
		printf("Error\n");
		exit(1);
	}
}

int	find_number_of_elements(char *line, int trg, int index)
{
	if (trg == 0)
		return (0);
	while (line[index] && line[index] != ' ')
		index++;
	while (line[index] && line[index] == ' ')
		index++;
	if (line[index] != '\0' && line[index] != '\n')
		return (0);
	return (1);
}

int	valid_finder(char *line, char *use_avail)
{
	int		trg;
	int		index;
	char	*temp;

	index = 0;
	if (line[0] == '\n')
		return (1);
	while (line[index] && line[index] != ' ')
		index++;
	if (!(index == 2 || index == 1))
		return (0);
	temp = ft_substr(line, 0, index);
	trg = find_arr(temp, use_avail);
	while (line[index] == ' ')
		index++;
	if (line[index] == '\0' || line[index] == '\n')
		trg = 0;
	trg = find_number_of_elements(line, trg, index);
	free(temp);
	return (trg);
}

int	parse_cardi_col(char *line, char *use_avail, t_data *data, int trg)
{
	if (trg == 2)
		return (2);
	if (valid_finder(line, use_avail))
		parse_line(data, line, use_avail);
	else
	{
		free(use_avail);
		free(line);
		return (1);
	}
	free(line);
	if (ft_strlen(use_avail) == 0)
	{
		free(use_avail);
		if (validate_text_info(data))
			return (1);
		return (2);
	}
	else
		return (0);
}
