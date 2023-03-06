/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:33:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/17 15:14:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		string_len;
	size_t		i;

	if (!s)
		return (NULL);
	string_len = ft_strlen(s);
	i = 0;
	if (len > string_len)
		len = string_len;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	if (start < string_len)
	{
		while (i < len)
			sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
