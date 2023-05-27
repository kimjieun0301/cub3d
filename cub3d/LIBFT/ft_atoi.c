/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:29:13 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 21:46:51 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	return_value;

	return_value = 0;
	sign = 1;
	while (*str == '\n' || *str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		return_value = return_value * 10 + *str - '0';
		str++;
	}
	return (return_value * sign);
}
