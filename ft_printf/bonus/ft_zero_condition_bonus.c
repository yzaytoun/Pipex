/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_condition_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:56:39 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/05/25 19:27:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_zero_condition(t_flag *flag)
{
	if (!ft_isdigit(flag->prev_dig) && !ft_isflag(flag->prev_dig))
		return (1);
	else if (ft_isdigit(flag->next_dig))
		return (1);
	return (0);
}
