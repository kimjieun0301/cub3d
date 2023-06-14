/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:50:49 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/09 23:31:11 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t maxsize)
{
	size_t	size;
	size_t	index;

	index = 0;
	size = ft_strlen(src);
	if (!maxsize)
		return (size);
	while (index < size && index + 1 < maxsize && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (size);
}
