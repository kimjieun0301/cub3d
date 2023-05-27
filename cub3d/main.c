/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:11:18 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/26 16:55:07 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/header.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc != 2 || parse_data(data, argv[1]) == 1)
	{
		printf("error\n");
		return (1);
	}
	draw_map(data);
	return (0);
}
