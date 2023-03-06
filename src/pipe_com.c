/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:21:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/24 20:39:13 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//SECTION - PIPES FUNCTIONS
//ANCHOR - READ FILE
void	ft_open(t_man *man, int flag)
{
	if (man->readfd.flag == 1 && flag == READ)
	{
		man->readfd.fd = open(man->readfd.name, O_RDONLY);
		if (man->readfd.fd <= 0)
		{
			man->readfd.flag = 0;
			perror(man->readfd.name);
			exit(EXIT_SUCCESS);
		}
	}
	if (man->writefd.flag == 1 && flag == WRITE)
	{
		man->writefd.fd = open(man->writefd.name,
				O_RDWR | O_TRUNC | O_CREAT, 0000644);
		if (man->writefd.fd <= 0)
		{	
			man->writefd.flag = 0;
			ft_error(man->writefd.name);
		}
	}
}

//ANCHOR - CLOSE PIPES
void	ft_close_pipes(t_man **man)
{
	(*man)->i = 0;
	while ((*man)->i < (*man)->pipenum)
	{
		if (close((*man)->pipes[(*man)->i][0]) < 0)
			ft_error("Close PIPE[0]");
		if (close((*man)->pipes[(*man)->i][1]) < 0)
			ft_error("Close PIPE[1]");
		(*man)->i++;
	}
}

//ANCHOR - PIPE
void	ft_pipe(t_man *man)
{
	man->pipes = ft_calloc(sizeof(int *), man->pipenum);
	if (!man->pipes)
		ft_error("No PIPES");
	man->i = 0;
	while (man->i < man->pipenum)
	{
		man->pipes[man->i] = ft_calloc(sizeof(int), 2);
		if (!man->pipes[man->i])
		{
			ft_free_pipes(man);
			ft_error("NO PIPES ALLOCATED");
		}
		man->i++;
	}
}

void	ft_dup2(int input, int output)
{
	if (input != STDIN_FILENO)
		if (dup2(input, STDIN_FILENO) < 0)
			ft_error("Dup IN failed");
	if (output != STDOUT_FILENO)
		if (dup2(output, STDOUT_FILENO) < 0)
			ft_error("Dup OUT failed");
}

//ANCHOR - PIPEX
void	ft_pipex(t_archlist *pip, t_man *man, char **envp)
{
	man->child = ft_calloc(sizeof(pid_t), man->command.count - 2);
	if (!man->child)
		ft_error("Child array is not allocated");
	man->pipenum = man->command.count - 3;
	ft_pipe(man);
	man->i = 0;
	while (man->i < man->pipenum)
	{
		if (pipe(man->pipes[man->i]) < 0)
			ft_error("Pipe failed");
		man->i++;
	}
	man->i = 2;
	ft_parent(pip, man, envp);
	ft_free_pipes(man);
}
//!SECTION