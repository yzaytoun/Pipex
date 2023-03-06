/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:20:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/04 12:01:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

//SECTION
//ANCHOR - MAIN_BONUS
int	main(int argc, char **argv, char **envp)
{
	t_man		*man;
	t_archlist	*pip;
	t_heredoc	*doc;

	if (argc > 4 && argc < ARG_MAX)
	{
		ft_allocate_bonus(&pip, &man, &doc);
		if (pip == NULL || pip->content == NULL || man == NULL || doc == NULL)
			ft_error("Failed to allocate");
		ft_allocate_command(&man, argc);
		ft_savepath(man, envp);
		ft_args(man, argv, doc);
		ft_findfiles_bonus(man, argv, doc);
		ft_findcomm_bonus(&pip, man, doc);
		ft_reverse_list(&pip);
		if (doc->flag == 1)
			ft_pipex_bonus(pip, man, envp);
		else
			ft_pipex(pip, man, envp);
		ft_free_all_bonus(pip, man, doc);
	}
	else
		ft_error("Minimum Four Argumentes Required");
	return (EXIT_SUCCESS);
}

//!SECTION