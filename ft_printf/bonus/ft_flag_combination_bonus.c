/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_combination_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:36:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/27 20:16:31 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_save_num(const char *s, t_flag *flag, t_pos *pos)
{
	int	num;
	int	i;

	num = 0;
	i = pos->counter;
	while (s[i] != '\0' && pos->breaker != 1)
	{
		if (ft_isdigit(s[i]))
		{
			num = num * 10 + (s[i] - '0');
			pos->counter += 1;
			if (s[i] == '0')
				pos->zero_num += 1;
		}
		else if (s[i] == '%' || (i == pos->pos_point && pos->pos_point > 0)
			|| (ft_isformat_bonus(s[i])))
			pos->breaker = 1;
		i++;
	}
	flag->width = num;
	pos->save_width = flag->width;
	pos->breaker = 0;
}

static void	ft_flag_type(char c, t_flag *flag)
{
	if (c == '-')
		flag->negative = 1;
	else if (c == '.')
		flag->point = 1;
	else if (c == '+')
		flag->positive = 1;
	else if (c == '0' && ft_zero_condition(flag))
		flag->zero = 1;
	else if (c == '#')
		flag->hash = 1;
	else if (c == 32 && (ft_isflag(flag->next_dig)
			|| ft_isformat_bonus(flag->next_dig)
			|| ft_isdigit(flag->next_dig)))
		flag->space = 1;
	flag->num += 1;
	if (c == '0' && (ft_isdigit(flag->prev_dig) || ft_isflag(flag->prev_dig)))
		flag->num -= 1;
}

static void	ft_find_format(const char *input, t_pos *pos)
{
	int	i;

	i = pos->counter;
	while (input[i] != '\0' && pos->breaker != 1)
	{
		if (ft_isformat_bonus(input[i]))
		{
			pos->format = input[i];
			pos->breaker = 1;
		}
		if (input[i] == '%')
			pos->breaker = 1;
		++i;
	}
	pos->breaker = 0;
}

void	ft_flag_combination_bonus(const char *input, t_pos *pos, t_flag *flag)
{
	int	i;

	i = pos->counter;
	ft_save_num(input, flag, pos);
	while (input[i] != '\0' && pos->breaker != 1)
	{
		if (ft_isflag(input[i]) || input[i] == '0')
		{
			flag->prev_dig = input[i - 1];
			flag->next_dig = input[i + 1];
			ft_flag_type(input[i], flag);
		}
		else if (input[i] == '%' || ft_isalpha(input[i]))
			pos->breaker = 1;
		++i;
	}
	if (flag->zero == 1)
		pos->counter -= 1;
	pos->breaker = 0;
	ft_find_format(input, pos);
	if (flag->point == 1)
		ft_get_precision_num(input, pos);
}
