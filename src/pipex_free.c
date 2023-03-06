/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:15:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/24 19:24:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
//SECTION - PIPEX FREE
//ANCHOR - Free Strings 
void	ft_archlist_del(t_archlist **list)
{
	t_archlist	*node;
	int			i;

	i = 0;
	if ((*list) == NULL || !list)
		ft_error("archlist is empty");
	node = (*list)->next;
	while (node != NULL)
	{
		(*list) = node->next;
		if (node->content->arg != NULL)
		{
			i = 0;
			while (node->content->arg[i] != NULL)
			{
				free(node->content->arg[i]);
				i++;
			}
			free(node->content->arg);
		}
		free(node->content->path);
		free(node->content);
		free(node);
		node = (*list);
	}
}

//ANCHOR - ALLOCATE calloc
void	ft_allocate(t_archlist **pip, t_man **man)
{
	(*pip) = ft_calloc(sizeof(t_archlist), 1);
	if (!(*pip))
		ft_error("Pipex is not allocated");
	(*pip)->content = ft_calloc(sizeof(t_string), 1);
	if (!(*pip)->content)
		ft_error("Pipex->content is not allocated");
	(*pip)->next = NULL;
	(*man) = ft_calloc(sizeof(t_man), 1);
	if (!(*man))
		ft_error("Manager is not allocated");
}

//ANCHOR - Free All

void	ft_free_all(t_archlist *pip, t_man *man)
{
	ft_archlist_del(&pip);
	free(pip);
	free(man->readfd.name);
	free(man->writefd.name);
	man->i = man->env.count;
	while (man->i >= 0)
		free(man->env.string[man->i--]);
	free(man->env.string);
	man->i = man->command.count;
	while (man->i >= 0)
	{
		free(man->command.string[man->i]);
		if (man->command.args[man->i] != NULL)
			free(man->command.args[man->i]);
		man->i--;
	}
	free(man->command.string);
	free(man->command.args);
	free(man->child);
	free(man);
}

//ANCHOR - Allocate commands and arguments 
void	ft_allocate_command(t_man **man, int ac)
{
	(*man)->counter = ac;
	(*man)->command.string = ft_calloc(sizeof(char *), (*man)->counter);
	if (!(*man)->command.string)
		ft_error("command strings is not allocated");
	(*man)->command.args = ft_calloc(sizeof(char *), (*man)->counter);
	if (!(*man)->command.args)
		ft_error("command args is not allocated");
}

void	ft_free_pipes(t_man *man)
{
	man->i = 0;
	while (man->i < man->pipenum)
	{
		free(man->pipes[man->i]);
		man->i++;
	}
	free(man->pipes);
}

//!SECTION