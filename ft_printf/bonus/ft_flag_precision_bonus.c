/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_precision_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:41:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/28 20:34:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_flag_write(t_pos *pos, t_flag *flag)
{
	if (flag->negative_arg == 1 && !ft_isunsigned(pos->format))
	{
		pos->len += write(1, "-", 1);
		flag->width += 1;
	}
	if (pos->format == 'p')
	{
		pos->len += write(1, "0x", 2);
		flag->width += 2;
	}
	while (flag->width > 0)
	{
		pos->len += write(1, "0", 1);
		flag->width -= 1;
	}
}

static void	ft_check_comb(t_pos *pos, t_flag *flag)
{
	flag->width = pos->precision_num - flag->count_digit;
	ft_flag_write(pos, flag);
}

void	ft_flag_precision_bonus(t_flag *flag, t_pos *pos)
{
	if (flag->negative_arg == 1 && flag->space == 1)
	{
		pos->len += write(1, "-", 1);
		flag->width += 1;
	}
	if (pos->format == 's')
		flag->cutstring = 1;
	else
		ft_check_comb(pos, flag);
}
