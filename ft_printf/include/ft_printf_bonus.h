/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:54:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/06/01 13:30:09 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include<stdio.h>
# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdint.h>
# include<limits.h>

typedef struct s_flags
{
	int			num;
	int			point;
	int			negative;
	int			positive;
	int			hash;
	int			zero;
	int			space;
	int			cutstring;
	int			width;
	int			print_zero;
	int			print_space;
	char		prev_dig;
	char		next_dig;
	int			negative_arg;
	int			positive_arg;
	int			diff;
	int			count_digit;
}				t_flag;

typedef struct s_pos
{
	int					counter;
	int					len;
	int					save_width;
	int					pos_flag;
	int					zero_num;
	int					pos_point;
	int					breaker;
	int					precision_num;
	char				format;
	unsigned long long	save_num;
	unsigned long long	hex_num;
}						t_pos;

int		ft_printf(const char *input, ...);
void	ft_count_digit_bonus(t_pos *pos, va_list *arg, t_flag *flag);
void	ft_flag_combination_bonus(const char *input, t_pos *pos, t_flag *flag);
void	ft_format_bonus(va_list *arg, t_pos *pos, t_flag *flag);
void	ft_flag_0_bonus(t_flag *flag, t_pos *pos);
void	*ft_calloc(size_t count, size_t size);
void	ft_hex_bonus(t_flag *flag, t_pos *pos);
void	ft_putnbr_bonus(long long int num, t_flag *flag, t_pos *pos);
void	ft_unsigned_putnbr_bonus(
			unsigned long long num, t_flag *flag, t_pos *pos);
void	ft_putstr_bonus(const char *s, t_flag *flag, t_pos *pos);
void	ft_bzero(void *s, size_t n);
void	ft_check_flag_bonus(t_flag *flag, t_pos *pos);
void	ft_flag_space_bonus(t_flag *flag, t_pos *pos);
void	ft_putchar_bonus(char c, t_pos *pos, t_flag *flag);
void	ft_flag_precision_bonus(t_flag *flag, t_pos *pos);
int		ft_isformat_bonus(char c);
void	ft_reset_flag_bonus(t_flag *flag);
int		ft_isunsigned(char c);
void	ft_get_precision_num(const char *s, t_pos *pos);
int		ft_zero_condition(t_flag *flag);
void	ft_flag_write_space(t_pos *pos, t_flag *flag);
#endif
