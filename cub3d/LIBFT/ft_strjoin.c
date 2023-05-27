/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:21:45 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 12:21:47 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index1;
	size_t	index2;
	char	*return_value;

	index1 = ft_strlen(s1);
	index2 = ft_strlen(s2);
	return_value = (char *)ft_calloc((index1 + index2 + 1), sizeof(char));
	if (!return_value)
		return (0);
	ft_strlcat(return_value, s1, index1 + 1);
	ft_strlcat(return_value, s2, index1 + index2 + 1);
	return (return_value);
}
