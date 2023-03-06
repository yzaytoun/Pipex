/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:15:43 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/11/24 20:36:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	write(fd, s, i);
	write(fd, "\n", 1);
	return (i);
}
