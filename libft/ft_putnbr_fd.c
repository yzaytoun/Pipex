/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:42:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/11/24 21:07:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int				i;
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

int	ft_putnbr_fd(int n, int fd)
{
	char			num[13];
	int				i;
	unsigned int	v;

	if (fd < 0)
		return (0);
	i = count(n);
	v = n;
	if (n < 0)
	{
		v = -n;
		num[0] = '-';
	}
	num[i] = 0;
	num[i - 1] = '0';
	while (v > 0)
	{
		i--;
		num[i] = 48 + (v % 10);
		v /= 10;
	}
	write(fd, num, count(n));
	return (count(n));
}
