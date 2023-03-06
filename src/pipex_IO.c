/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_IO.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:22:04 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 11:41:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//SECTION - PIPEX IO
//ANCHOR - Child
void	ft_child_write(t_man *man, char *path, char **arg, char **envp)
{
	ft_open(man, WRITE);
	ft_dup2(man->pipes[man->currpipe][0], man->writefd.fd);
	ft_close_pipes(&man);
	man->errorex = execve(path, arg, envp);
	if (man->errorex < 0)
	{
		ft_putstr_fd(ft_strjoin("command not found: ", path), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(127);
	}
}

void	ft_child_read(t_man *man, char *path, char **arg, char **envp)
{
	ft_open(man, READ);
	ft_dup2(man->readfd.fd, man->pipes[man->currpipe][1]);
	ft_close_pipes(&man);
	man->errorex = execve(path, arg, envp);
	if (man->errorex < 0)
	{
		ft_putstr_fd(ft_strjoin("command not found: ", path), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	ft_child_mid(t_man *man, char *path, char **arg, char **envp)
{
	ft_dup2(man->pipes[man->currpipe - 1][0], man->pipes[man->currpipe][1]);
	ft_close_pipes(&man);
	man->errorex = execve(path, arg, envp);
	if (man->errorex < 0)
	{
		ft_putstr_fd(ft_strjoin("command not found: ", path), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	ft_filter(t_man *man, char *path, char **arg, char **envp)
{
	man->child[man->childnum] = fork();
	if (man->child[man->childnum] == 0)
	{
		if (man->i == 2)
			ft_child_read(man, path, arg, envp);
		else if ((man->pipenum > 1 && man->currpipe < man->pipenum)
			&& man->i < man->command.count - 1)
			ft_child_mid(man, path, arg, envp);
		else if (man->i == man->command.count - 1)
			ft_child_write(man, path, arg, envp);
		else
			ft_error("");
	}
	else if (man->child[man->childnum] < 0)
		ft_error("Fork");
}

//ANCHOR - PARENT
void	ft_parent(t_archlist *pip, t_man *man, char **envp)
{
	t_archlist	*node;

	node = pip->next;
	while (man->i < man->command.count)
	{
		ft_filter(man, node->content->path, node->content->arg, envp);
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