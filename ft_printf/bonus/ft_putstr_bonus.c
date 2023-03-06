/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:11:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/25 19:28:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_cutstring(const char *s, t_flag *flag, t_pos *pos)
{
	int	i;

	i = 0;
	if (flag->negative == 0)
	{
		flag->width -= pos->precision_num;
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
	while (s[i] != '\0' && i < pos->precision_num)
	{
		pos->len += write(1, &s[i], 1);
		++i;
	}
}

static void	ft_check_negative(t_flag *flag, t_pos *pos)
{
	if (flag->point == 1 && flag->width > pos->precision_num)
		flag->width -= pos->precision_num;
	else
		flag->width -= flag->count_digit;
	if (flag->negative == 1)
	{
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
}

static void	ft_write_null(t_flag *flag, t_pos *pos)
{
	if (flag->point == 1 && flag->width > 0)
		pos->len += write(1, "(null)", flag->width);
	else if (flag->point == 1 && flag->width == 0 && pos->precision_num > 0)
		pos->len += write(1, "(null)", pos->precision_num);
	else
		pos->len += write(1, "(null)", 6);
}

void	ft_putstr_bonus(const char *s, t_flag *flag, t_pos *pos)
{
	unsigned int	i;

	i = 0;
	ft_check_flag_bonus(flag, pos);
	if (!s)
		ft_write_null(flag, pos);
	else if (flag->cutstring == 1)
		ft_cutstring(s, flag, pos);
	else
	{
		while (s[i] != '\0')
		{
			pos->len += write(1, &s[i], 1);
			++i;
		}
	}
	ft_check_negative(flag, pos);
	flag->cutstring = 0;
}
