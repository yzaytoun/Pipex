/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:38:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 15:05:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//ANCHOR - MARCOS
# define FUNC_NAME __FUNCTION__
# define TRUE 1
# define FALSE !TRUE
# define READ 0
# define WRITE 1

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include "get_next_line.h"

//ANCHOR - STRUCT DECLARATION
typedef struct s_string		t_string;
struct s_string
{
	char	**arg;
	char	*path;
};

typedef struct s_arclist	t_archlist;

struct s_arclist
{
	t_string	*content;
	t_archlist	*next;
};

typedef struct s_strnum		t_strnum;
struct s_strnum
{
	char	**string;
	int		count;
};

typedef struct s_file		t_file;
struct s_file
{
	char	*name;
	int		fd;
	int		flag;
};

typedef struct s_twostr		t_twostr;
struct s_twostr
{
	char	**string;
	char	**args;
	int		count;
};

typedef struct s_man		t_man;
struct s_man
{	
	int			counter;
	t_strnum	env;
	t_twostr	command;
	t_file		readfd;
	t_file		writefd;
	int			**pipes;
	pid_t		*child;
	int			childnum;
	int			pipenum;
	int			status;
	int			i;
	int			currpipe;
	int			len;
	int			errorex;
	int			docflag;
};

//ANCHOR - UTILS FUNC
char	*ft_find_path(char **env);
int		ft_count_char(const char *s, char c);
void	ft_findcomm(t_archlist **list, t_man *man);
char	*ft_access(t_man *man, char *com);
void	ft_savepath(t_man *man, char **env);

//ANCHOR - I/O FUNC
void	ft_parent(t_archlist *pip, t_man *man, char **envp);
void	ft_filter(t_man *man, char *path, char **arg, char **envp);
void	ft_child_write(t_man *man, char *path, char **arg, char **envp);
void	ft_child_read(t_man *man, char *path, char **arg, char **envp);
void	ft_child_mid(t_man *man, char *path, char **arg, char **envp);

//ANCHOR - PIPEX FREE
void	ft_allocate(t_archlist **pip, t_man **man);
void	ft_archlist_del(t_archlist **list);
void	ft_free_all(t_archlist *pip, t_man *man);
void	ft_allocate_command(t_man **man, int ac);
void	ft_free_pipes(t_man *man);

//ANCHOR - PIPEX LIST
void	ft_lstput(t_archlist **lst, char *content, char *av, char *command);
void	ft_get_args(t_man *man, char **av);
void	ft_error(const char *name);
int		ft_charpos(const char *s, char c);

//ANCHOR - PIPEX COM
void	ft_open(t_man *man, int flag);
void	ft_pipe(t_man *man);
void	ft_close_pipes(t_man **man);
void	ft_pipex(t_archlist *pip, t_man *man, char **envp);
void	ft_dup2(int intput, int output);

//ANCHOR - PIPEX AUXs
void	ft_findfiles(t_man **man, char **av);
void	ft_reverse_list(t_archlist **lst);
void	ft_checkfiles(t_man *man);

//ANCHOR - PIPEX STRING
char	**ft_copystringargs(const char *content, char *command);
void	ft_eval(int status);
#endif /*PIPEX_H*/
//!SECTION