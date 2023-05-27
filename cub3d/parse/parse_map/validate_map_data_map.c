/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_data_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:14:10 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/25 15:21:18 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

/*
1. [0] == 0이면 무조건 에러
2. 0이 나올때까지 공백이고 1이고 전부 넘김. 이후, 0이 나오면 상/하/좌/우 확인 1 || 0이 아니면 에러
	2-1. 이경우, NSWE는 0취급을 한다. 
----validate 파트, 여기까지 끝냄--------
3. 어디에 N이 있는지 확인.
4. 2의 과정을 반복하되, 위치를 기록
*/

int	found_first_zero(char **map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (map[index][0] == '0' || map[index][ft_strlen(map[index])
			- 2] == '0')
			return (1);
		index++;
	}
	if (!map[0])
		return (1);
	if (ft_strchr(map[0], '0') || ft_strchr(map[index - 1], '0'))
		return (1);
	return (0);
}

int	check_is_nswe_or_one(char **map, int index, int innr_i)
{
	if (map[index][innr_i] == 'N' || map[index][innr_i] == 'S' ||
		map[index][innr_i] == 'W' || map[index][innr_i] == 'E')
		return (1);
	if (map[index][innr_i] == '1' || map[index][innr_i] == '0')
		return (1);
	return (0);
}

int	check_boundary_line(char **map, int index, int innr_i)
{
	if (check_is_nswe_or_one(map, index, innr_i - 1)
		&& check_is_nswe_or_one(map, index, innr_i + 1)
		&& check_is_nswe_or_one(map, index - 1, innr_i)
		&& check_is_nswe_or_one(map, index + 1, innr_i))
		return (0);
	return (1);
}

int	validate_boundary_line(t_data *data)
{
	int	index;
	int	innr_i;
	int	trg;

	index = -1;
	innr_i = 0;
	data->map = temporary_map(data);
	if (found_first_zero(data->map))
		return (1);
	while (data->map[++index])
	{
		trg = 0;
		while (data->map[index][innr_i])
		{
			if (data->map[index][innr_i] == '0' || data->map[index][innr_i]
				== 'N' || data->map[index][innr_i] == 'S' || data->map[index]
				[innr_i] == 'E' || data->map[index][innr_i] == 'W')
				trg = check_boundary_line(data->map, index, innr_i);
			if (trg)
				return (1);
			innr_i++;
		}
		innr_i = 0;
	}
	return (0);
}
