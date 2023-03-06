/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:02:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/06/01 13:36:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_print(const char *input, t_pos *pos, va_list *arg)
{
	pos->counter += 1;
	ft_format(arg, input[pos->counter], pos);
	pos->counter += 1;
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	t_pos	*pos;
	int		len;

	len = 0;
	pos = ft_calloc(sizeof(t_pos), 1);
	if (!pos)
		return (len);
	va_start(arg, input);
	while (input[pos->counter] != '\0')
	{
		if (input[pos->counter] != '%')
		{
			pos->len += ft_putchar(input[pos->counter]);
			pos->counter += 1;
		}
		if (input[pos->counter] == '%')
			ft_print(input, pos, &arg);
	}
	len = pos->len;
	free(pos);
	va_end(arg);
	return (len);
}
