/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:29:50 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/09 23:32:08 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		index;
	char	*return_value;

	index = 0;
	len = ft_strlen(src);
	return_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!return_value)
		return (0);
	while (src[index])
	{
		return_value[index] = src[index];
		index++;
	}
	return_value[index] = 0;
	return (return_value);
}
