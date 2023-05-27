/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:06:51 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/12 15:11:21 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	size_t			index;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		index = -1;
		while (++index < len)
			d[index] = s[index];
	}
	else
	{
		index = len + 1;
		while (--index)
			d[index - 1] = s[index - 1];
	}
	return (dst);
}
