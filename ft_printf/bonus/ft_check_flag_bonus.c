/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:43:18 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/06/03 12:33:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_check_hex(t_flag *flag, t_pos *pos)
{
	if (pos->format == 'X' || pos->format == 'x')
		if (flag->negative_arg == 1 && pos->precision_num < pos->save_width
			&& pos->precision_num > flag->count_digit)
			flag->width += 1;
}

static void	ft_check_zero(t_flag *flag, t_pos *pos)
{
	if (pos->precision_num == 0 && pos->hex_num != 0)
		flag->width = pos->save_width - flag->count_digit;
	else if (pos->hex_num == 0 && pos->precision_num == 0)
		flag->width = pos->save_width;
	else if (pos->precision_num == pos->save_width)
		flag->width = 0;
	else
	{
		flag->diff = pos->precision_num - pos->save_width;
		if (flag->diff < 0)
			flag->diff *= -1;
		flag->width = flag->diff;
		if (pos->precision_num < flag->count_digit)
			flag->width -= (flag->count_digit - pos->precision_num);
		else if (pos->precision_num > flag->count_digit
			&& flag->negative_arg == 1)
			flag->width -= 1;
		if (pos->precision_num > pos->save_width)
			flag->width = 0;
	}
	ft_check_hex(flag, pos);
}

static void	ft_print_format(t_flag *flag, t_pos *pos)
{
	if (pos->format == 'i' || pos->format == 'd')
		flag->width += flag->count_digit;
	else if (pos->format == 'u' || pos->format == 'x' || pos->format == 'X'
		|| pos->format == 'p')
	{
		if (pos->format == 'p')
			flag->width -= 2;
		flag->width += flag->count_digit;
	}
	if (pos->save_width > pos->precision_num
		&& pos->precision_num < flag->count_digit && pos->precision_num != 0)
		flag->width -= (flag->count_digit - pos->precision_num);
	if (pos->hex_num == 0)
		flag->width += 1;
}

static void	ft_print_pad(t_flag *flag, t_pos *pos)
{
	flag->width = pos->save_width - (pos->precision_num + flag->count_digit);
	ft_print_format(flag, pos);
	if (pos->precision_num == 0 && flag->zero == 0)
	{
		if (pos->format == 'p')
			flag->width += 2;
		flag->width -= flag->count_digit;
	}
	if (pos->format == 's')
		flag->width = pos->save_width - pos->precision_num;
	if (flag->zero == 1)
		ft_check_zero(flag, pos);
	while (flag->width > 0)
	{
		pos->len += write(1, " ", 1);
		flag->width -= 1;
	}
	ft_flag_precision_bonus(flag, pos);
}

void	ft_check_flag_bonus(t_flag *flag, t_pos *pos)
{	
	if (flag->point == 1 && pos->save_width > 0 && flag->negative == 0)
		ft_print_pad(flag, pos);
	else if (flag->point == 1)
		ft_flag_precision_bonus(flag, pos);
	else if (flag->zero == 1)
		ft_flag_0_bonus(flag, pos);
	else if (flag->positive == 1 && flag->positive_arg == 1)
	{
		flag->width -= 1;
		pos->len += write(1, "+", 1);
	}
	else if (flag->space == 1)
		ft_flag_space_bonus(flag, pos);
	else if (flag->num == 0 && flag->width > 0)
	{
		flag->width -= flag->count_digit;
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
}
