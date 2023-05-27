/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:07:07 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/09 20:47:03 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	index;

	index = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size < dst_size + 1)
		return (src_size + size);
	if (size > dst_size + 1)
	{
		while (src[index] && dst_size + index + 1 < size)
		{
			dst[dst_size + index] = src[index];
			index++;
		}
	}
	dst[dst_size + index] = 0;
	return (src_size + dst_size);
}
