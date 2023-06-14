/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:30:28 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 15:58:43 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*save;

	index = 0;
	save = NULL;
	while (s[index])
	{
		if (s[index] == (char)c)
			save = (char *)s + index;
		index++;
	}
	if (c == '\0')
		return ((char *)s + index);
	return (save);
}
