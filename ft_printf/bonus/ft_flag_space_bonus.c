/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:42:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/20 18:37:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_check_point(t_flag *flag, t_pos *pos)
{	
	if (flag->point == 1)
	{
		pos->len += write(1, " ", 1);
		flag->width -= 1;
	}
}

void	ft_flag_space_bonus(t_flag *flag, t_pos *pos)
{
	ft_check_point(flag, pos);
	if (pos->format == 's' && flag->hash == 1)
	{
		flag->width += 2;
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
	else if (flag->positive_arg == 1 && pos->format != 's')
		pos->len += write(1, " ", 1);
	else
	{
		flag->width -= flag->count_digit;
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
}
