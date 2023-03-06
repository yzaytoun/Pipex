/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/17 15:31:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ch_found;
	size_t		i;

	ch_found = (const char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ch_found[i] == (unsigned char)c)
		{
			return ((void *)(ch_found + i));
		}
		++i;
	}
	return (0);
}
