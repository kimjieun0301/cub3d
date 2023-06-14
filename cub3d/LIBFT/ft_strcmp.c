/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:29:25 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/05/25 13:53:18 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (s1[index] > s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		if (s1[index] < s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	if (s1[index] == '\0')
	{
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	}
	return (0);
}
