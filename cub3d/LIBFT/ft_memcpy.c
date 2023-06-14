/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:41:08 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/12 14:48:54 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	index;
	char	*d;
	char	*s;

	if (!src && !dest)
		return (0);
	index = 0;
	d = dest;
	s = (char *)src;
	while (index < len)
	{
		d[index] = s[index];
		index++;
	}
	return (dest);
}
