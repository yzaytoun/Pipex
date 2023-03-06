/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:39:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/22 19:08:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar_bonus(char c, t_pos *pos, t_flag *flag)
{
	ft_check_flag_bonus(flag, pos);
	if (c == '%')
		pos->len += write(1, "%", 1);
	else
		pos->len += write(1, &c, 1);
	if (flag->negative == 1)
	{
		flag->width -= flag->count_digit;
		while (flag->width > 0)
		{
			pos->len += write(1, " ", 1);
			flag->width -= 1;
		}
	}
}
