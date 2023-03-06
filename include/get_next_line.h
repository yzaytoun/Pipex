/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:59:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/11/11 20:29:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr_get(const char *s, char c);
void	*ft_calloc_get(size_t count, size_t size);
char	*ft_strjoin_get(char *s1, char *s2);
char	*ft_get_next(char *stat, size_t new_l, size_t len);
char	*ft_get_line(char **str, size_t n);
void	*ft_memmove_get(char *dest, const char *src, size_t n);
#endif
