/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:29:28 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/12 15:16:33 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*string;

	string = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (string[index] == (unsigned char)c)
			return (string + index);
		index++;
	}
	return (0);
}
