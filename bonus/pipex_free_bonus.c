/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:35:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 11:09:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
//SECTION - PIPEX FREE BONUS
//ANCHOR - ALLOCATE BONUS
void	ft_allocate_bonus(t_archlist **pip, t_man **man, t_heredoc **doc)
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
	(*doc) = ft_calloc(sizeof(t_heredoc), 1);
	if (!(*doc))
		ft_error("DOC is not allocated");
}

//ANCHOR - Free All BONUS
void	ft_free_all_bonus(t_archlist *pip, t_man *man, t_heredoc *doc)
{
	free(doc->text);
	free(doc->delimiter);
	free(doc);
	ft_free_all(pip, man);
}

//ANCHOR - Filter bonus
void	ft_filter_bonus(t_man *man, char *path, char **arg, char **envp)
{
	man->child[man->childnum] = fork();
	if (man->child[man->childnum] == 0)
	{
		if (man->i == 3)
			ft_child_read_bonus(man, path, arg, envp);
		else if (man->pipenum > 1 && man->i < man->command.count - 1
			&& man->currpipe < man->pipenum)
			ft_child_mid(man, path, arg, envp);
		else if (man->i == man->command.count - 1)
			ft_child_write_bonus(man, path, arg, envp);
		else
			ft_error("");
	}
	else if (man->child[man->childnum] < 0)
		ft_error("Fork");
}

//ANCHOR - PIPEX BONUS
void	ft_pipex_bonus(t_archlist *pip, t_man *man, char **envp)
{
	man->child = ft_calloc(sizeof(pid_t), man->command.count - 3);
	if (!man->child)
		ft_error("Child array is not allocated");
	man->pipenum = man->command.count - 4;
	ft_pipe(man);
	man->i = 0;
	while (man->i < man->pipenum)
	{
		if (pipe(man->pipes[man->i]) < 0)
			ft_error("Pipe failed");
		man->i++;
	}
	man->i = 3;
	ft_parent_bonus(pip, man, envp);
	ft_free_pipes(man);
}

//ANCHOR - PARENT
void	ft_parent_bonus(t_archlist *pip, t_man *man, char **envp)
{
	t_archlist	*node;

	node = pip->next;
	while (man->i < man->command.count)
	{
		ft_filter_bonus(man, node->content->path, node->content->arg, envp);
		man->i += 1;
		man->childnum++;
		node = node->next;
		if (man->currpipe < man->pipenum - 1)
			man->currpipe++;
	}
	ft_checkfiles(man);
	ft_close_pipes(&man);
	man->i = 0;
	while (man->i < man->childnum)
	{
		waitpid(man->child[man->i], &man->status, 0);
		ft_eval(man->status);
		man->i++;
	}
}
//!SECTION