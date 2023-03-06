/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:32:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/18 19:42:27 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count(int n)
{
	size_t			i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		num = -n;
		++i;
	}
	while (num > 9)
	{
		num /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*num;
	size_t			i;
	unsigned int	v;

	i = count(n);
	v = n;
	num = malloc(sizeof(char) * (i + 1));
	if (!num)
		return (NULL);
	num[i--] = '\0';
	if (v == 0)
		num[i] = '0';
	if (n < 0)
	{
		v = -1 * n;
		num[0] = '-';
	}
	while (v > 0)
	{
		num[i--] = 48 + (v % 10);
		v /= 10;
	}
	return (num);
}
