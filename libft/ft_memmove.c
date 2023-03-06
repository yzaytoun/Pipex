/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 07:47:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/16 17:21:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*copy_dest;
	char	*copy_src;

	copy_dest = (char *)dst;
	copy_src = (char *)src;
	if (dst == src)
		return (dst);
	if (copy_src < copy_dest)
	{
		while (len--)
			*(copy_dest + len) = *(copy_src + len);
		return (dst);
	}
	else
		while (len--)
			*copy_dest++ = *copy_src++;
	return (dst);
}
