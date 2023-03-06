/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:09:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/21 19:33:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_sub(const char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			len++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

static char	*assign(const char *s, char c)
{
	char	*sub;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*copy_sub(char **new, char const *s, char c, size_t index)
{
	new[index] = assign(s, c);
	if (!new[index])
	{
		while (index > 0)
		{
			index--;
			free(new[index]);
		}
		free(new);
		return (NULL);
	}
	return (new[index]);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	count;
	char	**newstr;

	if (!s)
		return (NULL);
	index = 0;
	count = ft_count_sub(s, c);
	newstr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!newstr)
		return (NULL);
	while (index < count)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			newstr[index] = copy_sub(newstr, s, c, index);
		while (*s != '\0' && *s != c)
			s++;
		++index;
	}
	newstr[index] = NULL;
	return (newstr);
}
