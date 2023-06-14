/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:11:18 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/06/02 12:58:53 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/header.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc != 2 || parse_data(data, argv[1]) == 1)
	{
		printf("Error\n");
		return (1);
	}
	draw_map(data);
	return (0);
}
