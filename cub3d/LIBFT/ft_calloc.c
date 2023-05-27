/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:29:19 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 21:42:14 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*return_value;

	return_value = malloc(count * size);
	if (!(return_value))
		return (0);
	ft_bzero(return_value, (count * size));
	return (return_value);
}
