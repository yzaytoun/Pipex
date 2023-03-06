/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:31:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/28 20:35:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_converter(unsigned long long num, t_pos *pos, t_flag *flag)
{	
	char	*c;
	int		len;

	len = 0;
	if (pos->format == 'X')
		c = "0123456789ABCDEF";
	else
		c = "0123456789abcdef";
	if (num >= 16)
		len += ft_converter(num / 16, pos, flag);
	if (flag->point == 1 && pos->precision_num == 0 && num == 0)
		return (0);
	else
		len += write(1, (c + (num % 16)), 1);
	pos->save_num = len;
	return (len);
}

static void	ft_check_negative(t_flag *flag, t_pos *pos)
{
	flag->width = pos->save_width - pos->save_num;
	if (flag->point == 1 && pos->precision_num > pos->save_width)
		flag->width -= pos->precision_num;
	else if (flag->point == 1 && pos->precision_num <= pos->save_width)
	{
		flag->width = pos->save_width - pos->precision_num;
		if (flag->negative_arg == 1 || (int)pos->hex_num == INT_MIN
			|| (int)pos->hex_num == INT_MAX)
			flag->width = pos->save_width - pos->save_num;
		if (pos->precision_num == pos->save_width)
			flag->width -= pos->precision_num;
	}
	else
		flag->width = pos->save_width - pos->save_num;
	if (pos->format == 'p')
		flag->width -= 2;
	while (flag->width > 0)
	{
		pos->len += write(1, " ", 1);
		flag->width -= 1;
	}
}

static void	ft_check_hash(t_flag *flag, t_pos *pos)
{
	if (flag->hash == 1 && pos->hex_num == 0)
		return ;
	else if (flag->hash == 1 && flag->negative == 1)
	{
		if (pos->format == 'X')
			pos->len += write(1, "0X", 2);
		else
			pos->len += write(1, "0x", 2);
		flag->width -= 2;
	}
	else if (flag->hash == 1 && flag->print_zero != 1 && flag->zero != 1)
	{
		if (pos->format == 'X')
			pos->len += write(1, "0X", 2);
		else
			pos->len += write(1, "0x", 2);
	}
}

void	ft_hex_bonus(t_flag *flag, t_pos *pos)
{
	ft_check_flag_bonus(flag, pos);
	if (pos->format == 'X' || pos->format == 'x')
	{
		ft_check_hash(flag, pos),
		pos->len += ft_converter(pos->hex_num, pos, flag);
		if (flag->negative == 1)
			ft_check_negative(flag, pos);
	}
	else if (pos->format == 'p')
	{
		if (flag->point == 0)
			pos->len += write(1, "0x", 2);
		pos->len += ft_converter(pos->hex_num, pos, flag);
		if (flag->negative == 1)
			ft_check_negative(flag, pos);
	}
}
