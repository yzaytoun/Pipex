/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:27:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 11:12:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H/*PIPEX BONUS*/
# define PIPEX_BONUS_H

# include "pipex.h"

typedef struct s_heredoc	t_heredoc;
struct s_heredoc
{
	int		flag;
	char	*delimiter;
	char	*text;
	size_t	len;
};

//ANCHOR - HEREDOC BONUS
void	ft_open_bonus(t_man *man);
void	ft_heredoc(t_heredoc *doc);
void	ft_args(t_man *man, char **av, t_heredoc *doc);
void	ft_findcomm_bonus(t_archlist **list, t_man *man, t_heredoc *doc);

//ANCHOR - PIPEX Free
void	ft_allocate_bonus(t_archlist **pip, t_man **man, t_heredoc **doc);
void	ft_free_all_bonus(t_archlist *pip, t_man *man, t_heredoc *doc);
void	ft_pipex_bonus(t_archlist *pip, t_man *man, char **envp);
void	ft_parent_bonus(t_archlist *pip, t_man *man, char **envp);
void	ft_filter_bonus(t_man *man, char *path, char **arg, char **envp);

//ANCHOR - PIPEX AUX
void	ft_writetofile(t_heredoc *doc, int *fd);
void	ft_child_read_bonus(t_man *man, char *path, char **arg, char **envp);
void	ft_child_write_bonus(t_man *man, char *path, char **arg, char **envp);
void	ft_close_fd(int *fd);
void	ft_findfiles_bonus(t_man *man, char **av, t_heredoc *doc);
#endif /*PIPEX BONUS*/