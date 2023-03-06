/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:16:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/20 19:14:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_format(va_list *arg, char in, t_pos *pos)
{
	if (in == '%')
		pos->len += write(1, "%", 1);
	else if (in == 'c')
		pos->len += ft_putchar(va_arg(*arg, int));
	else if (in == 's')
		pos->len += ft_putstr(va_arg(*arg, char *));
	else if (in == 'X' || in == 'x' || in == 'p')
		pos->len += ft_hex(arg, in);
	else if (in == 'd' || in == 'i')
		pos->len += ft_putnbr(va_arg(*arg, int));
	else if (in == 'u')
		pos->len += ft_putnbr(va_arg(*arg, unsigned int));
	else
		return ;
}
