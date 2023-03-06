/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:15:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/12/08 17:01:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		i += write(1, "(null)", 6);
	}
	else
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			++i;
		}
	}
	return (i);
}
