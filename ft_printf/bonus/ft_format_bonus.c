/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:17:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/20 19:25:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_check_sign(va_list *arg, t_flag *flag)
{
	long int	a;

	a = va_arg(*arg, int);
	if (a >= 0)
		flag->positive_arg = 1;
	else
		flag->negative_arg = 1;
}

void	ft_format_bonus(va_list *arg, t_pos *pos, t_flag *flag)
{
	va_list	ar_for;

	va_copy(ar_for, *arg);
	ft_check_sign(arg, flag);
	if (pos->format == '%' || pos->format == 'c')
		ft_putchar_bonus(va_arg(ar_for, int), pos, flag);
	else if (pos->format == 's')
		ft_putstr_bonus(va_arg(ar_for, char *), flag, pos);
	else if (pos->format == 'X' || pos->format == 'x' || pos->format == 'p')
	{
		if (pos->format == 'p')
			pos->hex_num = va_arg(ar_for, uintptr_t);
		else
			pos->hex_num = va_arg(ar_for, unsigned int);
		ft_hex_bonus(flag, pos);
	}
	else if (pos->format == 'd' || pos->format == 'i')
		ft_putnbr_bonus(va_arg(ar_for, int), flag, pos);
	else if (pos->format == 'u')
		ft_unsigned_putnbr_bonus(va_arg(ar_for, unsigned int), flag, pos);
	va_end(ar_for);
}
