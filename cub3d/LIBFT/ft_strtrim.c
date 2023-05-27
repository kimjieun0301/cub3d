/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:59:38 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 14:23:16 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*return_val;

	start = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
	{
		if (end < 2)
			break ;
		end--;
	}
	if (end <= start)
		return (ft_strdup(""));
	return_val = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!return_val)
		return (0);
	ft_strlcpy(return_val, s1 + start, end - start + 1);
	return (return_val);
}
