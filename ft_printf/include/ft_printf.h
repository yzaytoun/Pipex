/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:35:55 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/10/04 19:53:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdio.h>
# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdint.h>
# include"ft_printf_bonus.h"
# include "../../libft/libft.h"

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
void	ft_format(va_list *arg, char in, t_pos *pos);
int		ft_hex(va_list *arg, char in);
int		ft_putnbr(long int num);
int		ft_isflag(char c);
#endif
