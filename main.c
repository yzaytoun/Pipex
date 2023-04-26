/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:14:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/26 18:53:22 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_man		*man;
	t_archlist	*pip;

	if (argc == 5)
	{
		ft_allocate(&pip, &man);
		if (pip == NULL || pip->content == NULL || man == NULL)
			ft_error("Failed to allocate");
		ft_allocate_command(&man, argc);
		ft_savepath(man, envp);
		ft_findfiles(&man, argv);
		ft_get_args(man, argv);
		ft_findcomm(&pip, man);
		ft_reverse_list(&pip);
		ft_pipex(pip, man, envp);
		ft_free_all(pip, man);
	}
	else
	{
		ft_printf("Invalid number of arguments, accepts 4, you passed %i\n",
			argc - 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
