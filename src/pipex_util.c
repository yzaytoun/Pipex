/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:22:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/26 18:59:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
//SECTION - PIPEX UTILS
//ANCHOR - GET PATH
char	*ft_find_path(char **env)
{
	char	*dest;

	dest = NULL;
	if (!env || *env == NULL)
		return (NULL);
	while (*env)
	{
		if (ft_strncmp("PATH", *env, 4) == 0)
		{
			dest = ft_substr(*env, 5, ft_strlen(*env) + 1);
			if (!dest)
				ft_error("Failed to copy path");
			return (dest);
		}
		++env;
	}
	return (dest);
}

//ANCHOR - COUNT CHARs
int	ft_count_char(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			++i;
		++s;
	}
	return (i);
}

//ANCHOR - Find Commands
void	ft_findcomm(t_archlist **list, t_man *man)
{
	int		j;
	char	*buff;

	j = 1;
	buff = NULL;
	while (j < man->command.count)
	{
		buff = ft_access(man, man->command.string[j]);
		if (buff == NULL)
			ft_lstput(list, man->command.string[j],
				man->command.args[j], man->command.string[j]);
		else
			ft_lstput(list, buff, man->command.args[j], man->command.string[j]);
		free(buff);
		++j;
	}
}

//ANCHOR - ACCESS
char	*ft_access(t_man *man, char *com)
{
	char	*dest;

	dest = NULL;
	man->i = 0;
	while (man->i <= man->env.count)
	{
		dest = ft_strjoin(man->env.string[man->i], com);
		if (access(dest, X_OK) == 0)
			return (dest);
		free(dest);
		man->i++;
	}
	return (NULL);
}

//ANCHOR - Save path in man->buff
void	ft_savepath(t_man *man, char **env)
{
	char	*full_env;

	man->i = 0;
	full_env = ft_find_path(env);
	if (full_env == NULL)
		ft_error("No enviroment variables");
	man->env.string = ft_split(full_env, ':');
	man->env.count = ft_count_char(full_env, ':') + 1;
	while (man->i < man->env.count && man->env.string[man->i] != NULL)
	{
		man->env.string[man->i] = ft_strjoin_get(man->env.string[man->i], "/");
		man->i++;
	}
	free(full_env);
}

//!SECTION 