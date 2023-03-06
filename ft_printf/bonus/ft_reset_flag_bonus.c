/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:44:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/25 19:47:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_reset_flag_bonus(t_flag *flag)
{
	flag->num = 0;
	flag->point = 0;
	flag->negative = 0;
	flag->positive = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->cutstring = 0;
	flag->width = 0;
	flag->print_zero = 0;
	flag->print_space = 0;
	flag->prev_dig = 0;
	flag->next_dig = 0;
	flag->negative_arg = 0;
	flag->positive_arg = 0;
	flag->count_digit = 0;
}
