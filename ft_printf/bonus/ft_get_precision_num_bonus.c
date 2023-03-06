/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision_num_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:18:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/26 20:48:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_get_precision_num(const char *s, t_pos *pos)
{
	int	i;
	int	num;

	i = pos->pos_point;
	num = 0;
	while (s[i] != '\0' && pos->breaker != 1)
	{
		if (ft_isdigit(s[i]))
		{
			num = num * 10 + (s[i] - '0');
			pos->counter += 1;
		}
		else if (s[i] == '%' || ft_isformat_bonus(s[i]))
			pos->breaker = 1;
		++i;
	}
	pos->precision_num = num;
	pos->breaker = 0;
}
