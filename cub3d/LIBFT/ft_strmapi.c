/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:50:17 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/17 21:56:39 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*return_val;

	index = 0;
	return_val = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!return_val)
		return (0);
	while (s[index])
	{
		return_val[index] = f(index, s[index]);
		index++;
	}
	return_val[index] = '\0';
	return (return_val);
}
