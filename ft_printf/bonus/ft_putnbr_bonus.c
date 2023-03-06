/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:29:23 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/25 19:16:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_check_flags(t_flag *flag)
{
	if (flag->point == 1 || flag->zero == 1)
		return (1);
	return (0);
}

static void	ft_negative(long long int *n, t_flag *flag, t_pos *pos)
{
	if ((flag->negative_arg == 1 && !ft_check_flags(flag)))
		pos->len += write(1, "-", 1);
	*n *= -1;
}

static void	ft_check_negative(long long int num, t_flag *flag, t_pos *pos)
{
	if (flag->negative == 1)
	{
		flag->width = pos->save_width;
		if (flag->point == 1 && num == 0 && pos->precision_num == 0)
			flag->width = pos->save_width;
		else if (flag->point == 1)
		{
			flag->width -= pos->precision_num;
			if (flag->negative_arg == 1)
				flag->width -= 1;
			if (num == INT_MIN || num == INT_MAX)
				flag->width -= pos->precision_num;
		}
		else
			flag->width -= flag->count_digit;
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
}

static int	ft_print_nbr(long long int num, t_flag *flag, t_pos *pos)
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

void	ft_putnbr_bonus(long long int num, t_flag *flag, t_pos *pos)
{
	pos->hex_num = num;
	ft_check_flag_bonus(flag, pos);
	if (num < 0)
	{
		if (num == INT_MIN)
		{
			if (!ft_check_flags(flag))
				pos->len += write (1, "-", 1);
			pos->len += write(1, "2", 1);
			num = 147483648;
		}
		else
			ft_negative(&num, flag, pos);
	}
	pos->len += ft_print_nbr(num, flag, pos);
	ft_check_negative(num, flag, pos);
}
