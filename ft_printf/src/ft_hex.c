/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:11:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/15 21:06:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_converter(unsigned long num, char in)
{
	char	*c;
	int		len;

	len = 0;
	if (in == 'X')
		c = "0123456789ABCDEF";
	else
		c = "0123456789abcdef";
	if (num >= 16)
		len += ft_converter(num / 16, in);
	len += write(1, (c + (num % 16)), 1);
	return (len);
}

int	ft_hex(va_list *arg, char in)
{
	int	len;

	len = 0;
	if (in == 'X' || in == 'x')
		len += ft_converter(va_arg(*arg, unsigned int), in);
	else if (in == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_converter(va_arg(*arg, uintptr_t), in);
	}
	return (len);
}
