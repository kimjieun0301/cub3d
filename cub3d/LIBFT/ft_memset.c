/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:05:37 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/09 16:35:27 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int input, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *)arr)[index] = (unsigned char) input;
		index++;
	}
	return (arr);
}
