/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:22:20 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/24 19:22:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
//SECTION 
//ANCHOR - ADD to PATH LIST
void	ft_lstput(t_archlist **lst, char *content, char *av, char	*command)
{
	t_archlist	*new;

	if ((*lst) == NULL || !lst || !content)
		return ;
	new = ft_calloc(sizeof(t_list), 1);
	if (!new)
		ft_error("Node is not allocated");
	new->content = ft_calloc(sizeof(t_string), 1);
	if (!new->content)
		ft_error("Content in node is not allocated");
	new->content->path = ft_strdup(content);
	new->content->arg = ft_copystringargs(av, command);
	new->next = (*lst);
	(*lst) = new;
}

//ANCHOR - Get Args
void	ft_get_args(t_man *man, char **av)
{
	int	len;

	len = 0;
	man->i = 1;
	while (man->i < man->counter)
	{
		if (ft_strchr(av[man->i], ' ') != NULL)
		{
			len = ft_charpos(av[man->i], ' ');
			man->command.string[man->command.count]
				= ft_substr(av[man->i], 0, len);
			man->command.args[man->command.count]
				= ft_substr(av[man->i], len + 1, ft_strlen(av[man->i]));
		}
		else
			man->command.string[man->command.count] = ft_strdup(av[man->i]);
		man->command.count++;
		man->i++;
	}
	man->command.string[man->command.count] = NULL;
}

//ANCHOR - Error
void	ft_error(const char *name)
{
	perror(ft_strjoin("Command not found ", name));
	exit(EXIT_FAILURE);
}

//ANCHOR - CHAR POS
int	ft_charpos(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (0);
}
//!SECTION 
