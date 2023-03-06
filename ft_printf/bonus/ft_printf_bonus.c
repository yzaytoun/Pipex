/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 08:38:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/06/02 08:40:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_check_point(const char *s, t_pos *pos)
{
	int	i;
	int	num;

	i = pos->counter;
	num = 0;
	while (s[i] != '\0' && pos->breaker != 1)
	{
		if (s[i] == '.')
		{
			pos->pos_point = i;
			pos->breaker = 1;
		}
		else if (s[i] == '%')
			pos->breaker = 1;
		++i;
	}
	pos->breaker = 0;
}

static void	ft_find_flag(const char *s, t_pos *pos)
{
	int	i;

	i = pos->counter;
	while (s[i] != '\0' && pos->breaker != 1)
	{
		if (ft_isflag(s[i]) || (s[i] == '0' && !ft_isdigit(s[i - 1])))
		{
			pos->pos_flag = i;
			pos->breaker = 1;
		}
		else if (s[i] == '%')
			pos->breaker = 1;
		++i;
	}
	pos->breaker = 0;
}

static void	ft_print_flag(const char *str, t_pos *pos, va_list *arg)
{
	t_flag	*flag;

	flag = ft_calloc(1, sizeof(t_flag));
	if (!flag)
		return ;
	ft_find_flag(str, pos);
	ft_check_point(str, pos);
	ft_flag_combination_bonus(str, pos, flag);
	ft_count_digit_bonus(pos, arg, flag);
	pos->counter += flag->num;
	ft_format_bonus(arg, pos, flag);
	ft_reset_flag_bonus(flag);
	free(flag);
}

static void	ft_print(const char *input, t_pos *pos, va_list *arg)
{
	pos->counter += 1;
	if (ft_isflag(input[pos->counter]) || ft_isdigit(input[pos->counter]))
		ft_print_flag(input, pos, arg);
	else
		ft_format(arg, input[pos->counter], pos);
	pos->counter += 1;
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	t_pos	*pos;
	int		len;

	len = 0;
	pos = ft_calloc(sizeof(t_pos), 1);
	if (!pos)
		return (len);
	va_start(arg, input);
	while (input[pos->counter] != '\0')
	{
		if (input[pos->counter] != '%')
		{
			pos->len += ft_putchar(input[pos->counter]);
			pos->counter += 1;
		}
		if (input[pos->counter] == '%')
			ft_print(input, pos, &arg);
	}
	len = pos->len;
	free(pos);
	va_end(arg);
	return (len);
}
