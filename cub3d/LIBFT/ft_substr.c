/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:44:27 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 16:41:41 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_value;
	size_t	index;

	index = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	return_value = (char *)malloc((sizeof(char)) * (len + 1));
	if (!return_value)
		return (0);
	ft_bzero(return_value, len + 1);
	while (s[start] && index < len)
	{
		return_value[index] = s[start];
		index++;
		start++;
	}
	return_value[len] = 0;
	return (return_value);
}
