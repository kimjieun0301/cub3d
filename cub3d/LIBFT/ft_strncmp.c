/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:30:15 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/12 12:40:43 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && index < n)
	{
		if (s1[index] > s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		if (s1[index] < s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	if (s1[index] == '\0' && index < n)
	{
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	}
	return (0);
}
