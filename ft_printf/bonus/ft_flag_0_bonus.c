/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_0_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:36:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/27 19:36:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_unsigned_int(char c)
{
	if (c == 'x' || c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

static void	ft_flag_positive_0(t_flag *flag, t_pos *pos)
{
	pos->len += write(1, "+", 1);
	flag->width -= 1;
}

static void	ft_write_zeros(t_flag *flag, t_pos *pos)
{
	flag->width = pos->save_width - flag->count_digit;
	while (flag->width > 0)
	{
		pos->len += write(1, "0", 1);
		flag->width -= 1;
	}
}

static void	ft_flag_hash_0(t_flag *flag, t_pos *pos)
{
	if (pos->format == 'X')
		pos->len += write(1, "0X", 2);
	else
		pos->len += write(1, "0x", 2);
	flag->width -= 2;
}

void	ft_flag_0_bonus(t_flag *flag, t_pos *pos)
{
	if (flag->negative_arg == 1 && !ft_unsigned_int(pos->format))
		pos->len += write(1, "-", 1);
	else if (flag->space == 1)
	{
		pos->len += write(1, " ", 1);
		flag->width -= 1;
	}
	else if (flag->hash == 1 && (pos->format == 'x' || pos->format == 'X'))
		ft_flag_hash_0(flag, pos);
	else if (flag->positive == 1 && flag->positive_arg == 1)
		ft_flag_positive_0(flag, pos);
	ft_write_zeros(flag, pos);
}
