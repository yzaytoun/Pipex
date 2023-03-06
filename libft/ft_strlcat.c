/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:29:22 by vvila             #+#    #+#             */
/*   Updated: 2022/04/16 19:31:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	j = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		return (len_src + size);
	else
	{
		while (src[j] && (len_dst + j) < size)
			dst[i++] = src[j++];
		if ((len_dst + j) == size && len_dst < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (len_dst + len_src);
	}
}
