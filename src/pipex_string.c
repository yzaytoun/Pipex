/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:52:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/04 11:58:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static size_t	ft_stringarray_len(char **arr)
{
	size_t	len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len] != NULL)
		++len;
	return (len);
}

char	**ft_copystringargs(const char *content, char *command)
{
	char	**dest;
	char	**copy;
	int		index;
	int		len;

	len = 0;
	dest = ft_split(content, ' ');
	index = ft_stringarray_len(dest);
	copy = ft_calloc(sizeof(char *), index + 2);
	if (!copy)
		return (NULL);
	copy[0] = ft_strdup(command);
	index = 1;
	while (dest != NULL && dest[len] != NULL)
	{
		copy[index] = ft_strdup(dest[len]);
		free(dest[len]);
		index++;
		len++;
	}
	free(dest);
	copy[index] = NULL;
	return (copy);
}

void	ft_eval(int status)
{
	int	exitstat;

	exitstat = status;
	if (WIFEXITED(exitstat))
	{
		exitstat = WEXITSTATUS(exitstat);
		if (exitstat != 0)
			exit(exitstat);
	}
}
