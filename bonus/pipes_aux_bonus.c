/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_aux_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:50:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 11:46:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_writetofile(t_heredoc *doc, int *fd)
{
	char	*line;

	line = "";
	doc->len = ft_strlen(doc->delimiter);
	while (1 && line != NULL)
	{
		ft_printf("here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_close_fd(fd);
			ft_error("Get next line");
		}
		if (ft_strncmp(line, doc->delimiter, doc->len) == 0)
		{
			ft_close_fd(fd);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	ft_child_read_bonus(t_man *man, char *path, char **arg, char **envp)
{
	ft_dup2(STDIN_FILENO, man->pipes[man->currpipe][1]);
	ft_close_pipes(&man);
	man->errorex = execve(path, arg, envp);
	if (man->errorex < 0)
	{
		ft_putstr_fd(ft_strjoin("command not found: ", path), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	ft_child_write_bonus(t_man *man, char *path, char **arg, char **envp)
{
	ft_open_bonus(man);
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

void	ft_close_fd(int *fd)
{
	if (close(fd[0]) < 0)
		ft_error("Close fd");
	if (close(fd[1]) < 0)
		ft_error("Close fd");
}

void	ft_findfiles_bonus(t_man *man, char **av, t_heredoc *doc)
{
	if (doc->flag == 0)
	{
		man->readfd.name = ft_strdup(av[1]);
		man->readfd.flag = 1;
	}
	man->writefd.name = ft_strdup(av[man->counter - 1]);
	man->writefd.flag = 1;
}
