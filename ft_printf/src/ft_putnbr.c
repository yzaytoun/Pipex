/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:46:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/15 19:32:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	negative(long int *n, int *len)
{
	*len += write(1, "-", 1);
	*n *= -1;
}

int	ft_putnbr(long int num)
{
	int	len;

	len = 0;
	if (num >= -2147483648 || num <= 2147483647)
	{
		if (num == -2147483648)
		{
			len += write (1, "-2", 2);
			num = 147483648;
		}
		if (num < 0)
			negative(&num, &len);
		if (num >= 10)
		{
			len += ft_putnbr(num / 10);
			num %= 10;
		}
		if (num < 10)
			len += ft_putchar(num + '0');
	}
	return (len);
}
