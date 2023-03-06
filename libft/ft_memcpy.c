/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:24:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/17 15:31:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	dest = (char *)dst;
	source = (const char *)src;
	if ((dst == src) || n == 0)
		return (dst);
	while (n--)
			dest[n] = source[n];
	return (dst);
}
