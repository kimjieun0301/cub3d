/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:30:25 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/09 20:46:22 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	innr_index;

	index = 0;
	innr_index = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[index])
	{
		while (big[index + innr_index] == little[innr_index]
			&& big[index + innr_index])
			innr_index++;
		if (little[innr_index] == '\0' && index + innr_index <= len)
			return ((char *)big + index);
		innr_index = 0;
		index++;
	}
	return (0);
}
