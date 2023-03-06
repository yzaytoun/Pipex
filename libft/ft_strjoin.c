/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:09:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/17 08:30:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full_string;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	full_string = (char *)malloc(sizeof(char) * total_len);
	if (!full_string)
		return (NULL);
	ft_memmove(full_string, s1, ft_strlen(s1));
	ft_memmove(full_string + (ft_strlen(s1)), s2, ft_strlen(s2));
	full_string[total_len - 1] = '\0';
	return (full_string);
}
