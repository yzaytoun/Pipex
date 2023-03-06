/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:43:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/10/29 16:44:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	len;

	len = 0;
	count = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[count] != '\0' && count < (size - 1))
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (len);
}
