/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:35:10 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 11:11:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

//SECTION - HEREDOC
//ANCHOR - OPEN FILES BONUS
void	ft_open_bonus(t_man *man)
{
	man->writefd.fd = open(man->writefd.name,
			O_RDWR | O_CREAT | O_APPEND, 0000644);
	if (man->writefd.fd <= 0)
		ft_error("Output file");
}

//ANCHOR - GET ARGS BONUS
void	ft_args(t_man *man, char **av, t_heredoc *doc)
{
	man->i = 1;
	while (man->i < man->counter)
	{
		if (ft_strncmp(av[man->i], "here_doc", 9) == 0)
		{
			doc->flag = 1;
			doc->delimiter = ft_strdup(av[man->i + 1]);
			ft_heredoc(doc);
		}
		else if (ft_strchr(av[man->i], ' ') != NULL)
		{
			man->len = ft_charpos(av[man->i], ' ');
			man->command.string[man->command.count]
				= ft_substr(av[man->i], 0, man->len);
			man->command.args[man->command.count]
				= ft_substr(av[man->i], man->len + 1, ft_strlen(av[man->i]));
		}
		else
			man->command.string[man->command.count] = ft_strdup(av[man->i]);
		man->command.count++;
		man->i++;
	}
	man->command.string[man->command.count] = NULL;
}

//ANCHOR - Heredoc
void	ft_heredoc(t_heredoc *doc)
{
	pid_t	child;
	int		status;
	int		pipo[2];

	status = 0;
	if (pipe(pipo) < 0)
		ft_error("PIPE in Heredoc");
	child = fork();
	if (child == 0)
		ft_writetofile(doc, pipo);
	else if (child < 0)
		ft_error("FORK in Heredoc");
	else
	{
		ft_dup2(pipo[0], STDOUT_FILENO);
		ft_close_fd(pipo);
	}
	waitpid(child, &status, 0);
	ft_eval(status);
}

//ANCHOR - FIND COMMANDS
void	ft_findcomm_bonus(t_archlist **list, t_man *man, t_heredoc *doc)
{
	int		j;
	char	*buff;

	j = 1;
	buff = NULL;
	if (doc->flag == 1)
	{
		j = 2;
		man->docflag = 1;
	}
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
//!SECTION