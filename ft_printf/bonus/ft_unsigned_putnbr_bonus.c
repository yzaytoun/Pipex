/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:39:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/25 19:14:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_write_width(t_flag *flag, t_pos *pos)
{
	while (flag->width > 0)
	{
		pos->len += write(1, " ", 1);
		flag->width -= 1;
	}
}

static void	ft_check_negative(unsigned long long num, t_flag *flag, t_pos *pos)
{
	if (flag->negative == 1)
	{
		flag->width = pos->save_width;
		if (flag->point == 1 && num == 0 && pos->precision_num == 0)
			flag->width = pos->save_width;
		else if (flag->point == 1)
		{
			flag->width -= pos->precision_num;
			if (pos->save_width == pos->precision_num)
				flag->width = 0;
			else if ((int)num == INT_MIN || (int)num == INT_MAX
				|| (long)num == LONG_MIN || (long)num == LONG_MAX
				|| flag->negative_arg == 1)
				flag->width = pos->save_width - flag->count_digit;
			else if (flag->negative_arg == 1
				&& pos->save_width > flag->count_digit)
				flag->width = pos->precision_num;
		}
		else
			flag->width -= flag->count_digit;
		ft_write_width(flag, pos);
	}
}

static int	ft_print_unsigned(
		unsigned long long num, t_flag *flag, t_pos *pos)
{
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_putnbr(num / 10);
	if (flag->point == 1 && pos->precision_num == 0 && num == 0)
		return (0);
	else
		len += ft_putchar((num % 10) + '0');
	return (len);
}

void	ft_unsigned_putnbr_bonus(
		unsigned long long num, t_flag *flag, t_pos *pos)
{
	pos->hex_num = num;
	ft_check_flag_bonus(flag, pos);
	pos->len += ft_print_unsigned(num, flag, pos);
	ft_check_negative(num, flag, pos);
}
