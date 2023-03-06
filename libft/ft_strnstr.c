/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:26:23 by vvila             #+#    #+#             */
/*   Updated: 2022/04/16 20:07:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;
	size_t	s_n;
	size_t	count;

	i = 0;
	str = (char *)haystack;
	s_n = ft_strlen(needle);
	if (s_n == 0 || haystack == needle)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		count = 0;
		while ((str[i + count] != '\0' && needle[count] != '\0')
			&& (str[i + count] == needle[count] && (i + count < len)))
			count++;
		if (count == s_n)
			return (str + i);
		i++;
	}
	return (0);
}
