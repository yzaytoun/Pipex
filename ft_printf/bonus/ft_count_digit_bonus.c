/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:44:52 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/25 19:10:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_hexa(unsigned long long n, t_flag *flag, t_pos *pos)
{
	size_t				i;
	unsigned long long	num;

	i = 1;
	num = n;
	while (num >= 16)
	{
		num /= 16;
		++i;
	}
	if (pos->format == 'p')
		i += 2;
	flag->count_digit = i;
}

static void	ft_int(long int n, t_flag *flag)
{
	size_t			i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		num = -n;
		++i;
	}
	while (num > 9)
	{
		num /= 10;
		++i;
	}
	flag->count_digit = i;
}

static void	ft_int_unsigned(unsigned long long n, t_flag *flag, t_pos *pos)
{
	size_t				i;
	unsigned long long	num;

	i = 1;
	num = n;
	pos->save_num = num;
	while (num > 9)
	{
		num /= 10;
		++i;
	}
	flag->count_digit = i;
}

static void	ft_str(char *s, t_flag *flag, t_pos *pos)
{
	int	i;

	i = 0;
	if (!s)
	{
		flag->count_digit = 6;
		if (flag->width > flag->count_digit && flag->point == 1)
			flag->width = 6;
		else if (pos->precision_num > flag->count_digit && flag->point == 1)
			pos->precision_num = 6;
		return ;
	}
	while (s[i] != '\0')
		++i;
	flag->count_digit = i;
}

void	ft_count_digit_bonus(t_pos *pos, va_list *arg, t_flag *flag)
{
	va_list	arg_c;

	va_copy(arg_c, *arg);
	if (pos->format == 's')
		ft_str(va_arg(arg_c, char *), flag, pos);
	else if (pos->format == 'i' || pos->format == 'd')
		ft_int(va_arg(arg_c, int), flag);
	else if (pos->format == 'u')
		ft_int_unsigned(va_arg(arg_c, unsigned int), flag, pos);
	else if (pos->format == 'x' || pos->format == 'X')
		ft_hexa(va_arg(arg_c, unsigned int), flag, pos);
	else if (pos->format == 'p')
		ft_hexa(va_arg(arg_c, uintptr_t), flag, pos);
	else if (pos->format == 'c')
		flag->count_digit = 1;
	va_end(arg_c);
}
