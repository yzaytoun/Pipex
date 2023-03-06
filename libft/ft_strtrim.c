/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 08:36:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/17 09:34:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	compare(char const c, char const *p)
{
	while (*p)
	{
		if (c == *p)
			return (1);
		p++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	start;
	size_t	fin;
	size_t	index;

	if (!s1 || !set)
		return (NULL);
	fin = ft_strlen(s1);
	start = 0;
	index = 0;
	while (s1[start] && compare(s1[start], set))
		start++;
	while (fin > start && compare(s1[fin - 1], set))
		fin--;
	newstr = (char *)malloc(sizeof(char) * (fin - start + 1));
	if (!newstr)
		return (NULL);
	while (start < fin)
		newstr[index++] = s1[start++];
	newstr[index] = '\0';
	return (newstr);
}
