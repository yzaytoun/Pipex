/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/04/19 17:47:32 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*point;
	t_list	*next_p;

	if (!lst || !del)
		return ;
	point = (*lst);
	(*lst) = point->next;
	while (point != NULL)
	{
		next_p = point->next;
		(del)(point->content);
		free(point);
		point = next_p;
	}
	(*lst) = NULL;
}
