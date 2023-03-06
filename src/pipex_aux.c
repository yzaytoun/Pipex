/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:31:13 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/02/25 11:02:19 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
//SECTION - PIPEX AUX
//ANCHOR - LIST SORTING
void	ft_reverse_list(t_archlist **lst)
{
	t_archlist	*next;
	t_archlist	*current;
	t_archlist	*prev;

	next = NULL;
	prev = NULL;
	current = (*lst);
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*lst) = prev;
}

//ANCHOR - Find Files
void	ft_findfiles(t_man **man, char **av)
{
	(*man)->readfd.name = ft_strdup(av[1]);
	(*man)->readfd.flag = 1;
	(*man)->writefd.name = ft_strdup(av[(*man)->counter - 1]);
	(*man)->writefd.flag = 1;
}

//ANCHOR - CHECK FILES
void	ft_checkfiles(t_man *man)
{
	if (man->docflag == 0)
	{
		man->readfd.fd = open(man->readfd.name, O_RDONLY);
		if (man->readfd.fd <= 0)
			man->readfd.flag = 0;
	}
	if (access(man->writefd.name, F_OK & R_OK) < 0)
		man->writefd.flag = 0;
}

//!SECTION