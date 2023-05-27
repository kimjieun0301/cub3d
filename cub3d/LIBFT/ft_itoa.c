/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:50:48 by seokjyoo          #+#    #+#             */
/*   Updated: 2022/07/18 12:20:43 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*size_smaller_zero(int n, size_t len)
{
	char	*return_val;

	if (n != -2147483648)
		n *= -1;
	else
	{
		return_val = (char *)malloc(sizeof(char) * 12);
		ft_strlcpy(return_val, "-2147483648", 12);
		return (return_val);
	}
	return_val = (char *)malloc(sizeof(char) * (len + 1));
	if (!return_val)
		return (0);
	return_val[len] = 0;
	while (len--)
	{
		return_val[len] = (n % 10) + '0';
		if (len == 0)
			return_val[0] = '-';
		n /= 10;
	}
	return (return_val);
}

static char	*return_zero(void)
{
	char	*return_val;

	return_val = (char *)malloc(sizeof(char) * 2);
	if (!return_val)
		return (0);
	return_val[0] = '0';
	return_val[1] = 0;
	return (return_val);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		len_n;
	char	*return_val;

	len = 0;
	len_n = n;
	while (len_n)
	{
		len++;
		len_n /= 10;
	}
	if (n < 0)
		return (size_smaller_zero(n, len + 1));
	if (n == 0)
		return (return_zero());
	return_val = (char *)malloc(sizeof(char) * (len + 1));
	if (!return_val)
		return (0);
	return_val[len] = 0;
	while (len--)
	{
		return_val[len] = (n % 10) + '0';
		n /= 10;
	}
	return (return_val);
}
