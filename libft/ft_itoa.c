/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:54:29 by tdontos-          #+#    #+#             */
/*   Updated: 2018/12/01 14:54:30 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		itoa_len(int n)
{
	int i;

	i = 0;
	if (n <= -2147483648)
		return (0);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (++i);
}

char			*ft_itoa(int n)
{
	char	*arr;
	int		i;
	int		neg;

	neg = 1;
	if ((i = itoa_len(n)) == 0)
		return (ft_strdup("-2147483648"));
	if ((arr = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	arr[i] = '\0';
	while (i > 0)
	{
		arr[--i] = n % 10 + '0';
		n /= 10;
	}
	if (neg < 0)
		arr[i] = '-';
	return (arr);
}
